#include "dataframe.h"

Dataframe::Dataframe()
{
    this->shape.first = NUMBER_OF_ROWS;
    this->shape.second = NUMBER_OF_COLUMNS;

    this->Min = vector<double>(NUMBER_OF_COLUMNS);
    this->Max = vector<double>(NUMBER_OF_COLUMNS);
    this->Mean = vector<double>(NUMBER_OF_COLUMNS);
    this->Variance = vector<double>(NUMBER_OF_COLUMNS);
}
Dataframe::~Dataframe() {}

Dataframe *Dataframe::read_csv(string path)
{
    Logger *console = Logger::get_logger();
    Dataframe *df = new Dataframe();

    CSV_Parser parser;
    string line, value;
    stringstream ss;

    parser.read_file(path);
    ss << parser.get_data();
    for (int i = 0; i < df->shape.second; i++)
    {
        if (i != df->shape.second - 1)
            getline(ss, value, ',');
        else
            getline(ss, value, '\n');

        df->columns.push_back(value);
        df->data.push_back(vector<double>(NUMBER_OF_ROWS));
    }

    for (int row=0; row < df->shape.first; row++){

        for (int col = 0; col < df->shape.second; col++){
            if (col != df->shape.second - 1)
                getline(ss, value, ',');
            else
                getline(ss, value, '\n');

            df->data[col][row] = stod(value);
        }

    }

    df->statistics_();

    return df;
}

void Dataframe::statistics_()
{
    for (int i = 0; i < this->shape.second; i++)
    {
        double min = *min_element(data[i].begin(), data[i].end());

        double max = *max_element(data[i].begin(), data[i].end());

        double sum = accumulate(data[i].begin(), data[i].end(), 0.0);
        double mean = sum / this->shape.first;

        double sum_sq = inner_product(data[i].begin(), data[i].end(), data[i].begin(), 0.0);
        double variance = sum_sq / this->shape.first - mean * mean;

        this->Min[i] = min;
        this->Max[i] = max;
        this->Mean[i] = mean;
        this->Variance[i] = variance;
    }
}

vector<double> Dataframe::operator[](int column_index)
{
    return this->data[column_index];
}

double Dataframe::min(int column_index) { return this->Min[column_index]; }
double Dataframe::max(int column_index) { return this->Max[column_index]; }
double Dataframe::mean(int column_index) { return this->Mean[column_index]; }
double Dataframe::variance(int column_index) { return this->Variance[column_index]; }
double Dataframe::std(int column_index) { return sqrt(this->Variance[column_index]); }

void Dataframe::collect(int rows = -1)
{
    if (rows == -1 || rows > this->shape.first)
        rows = this->shape.first;

    Logger *console = Logger::get_logger();
    string msg = "";
    stringstream ss;
    string tmp;

    for (int i = 0; i < this->shape.second; i++)
    {
        msg += this->columns[i] + ", ";
    }

    console->log(msg);
    msg = "";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < this->shape.second; j++)
        {
            msg += to_string(this->data[j][i]) + ", ";
        }
        console->log(msg);
        msg = "";
    }
}

void Dataframe::describe()
{
    Logger *console = Logger::get_logger();
    string msg = "";
    stringstream ss;
    string tmp;

    for (int i = 0; i < this->shape.second; i++)
    {
        msg += this->columns[i] + ", ";
    }

    console->log(msg);
    msg = "Min:  ";

    for (int i = 0; i < this->shape.second; i++)
    {
        msg += to_string(this->Min[i]) + ", ";
    }

    console->log(msg);
    msg = "Max:  ";

    for (int i = 0; i < this->shape.second; i++)
    {
        msg += to_string(this->Max[i]) + ", ";
    }

    console->log(msg);
    msg = "Mean: ";

    for (int i = 0; i < this->shape.second; i++)
    {
        msg += to_string(this->Mean[i]) + ", ";
    }

    console->log(msg);
    msg = "Var:  ";

    for (int i = 0; i < this->shape.second; i++)
    {
        msg += to_string(this->Variance[i]) + ", ";
    }

    console->log(msg);
}