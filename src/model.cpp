#include "model.h"

Model::Model() {}
Model::~Model() {}

DecisionTreeAdaptor::DecisionTreeAdaptor() {}
DecisionTreeAdaptor::~DecisionTreeAdaptor()
{
    if (this->tree_ != nullptr)
        delete this->tree_;
}

void DecisionTreeAdaptor::fit(Dataframe *df)
{
    Logger *console = Logger::get_logger();
    console->log("Constructing Decision Tree");

    this->tree_ = new DecisionTree(df->data);
}

vector<int> DecisionTreeAdaptor::predict(Dataframe *df)
{
    vector<int> label = df->data[df->data.size() - 1];
    df->data.pop_back();
    vector<int> pred = this->tree_->predict(df->data);
    df->data.push_back(label);

    return label;
}

float DecisionTreeAdaptor::evaluate(Dataframe *df)
{
    Logger *console = Logger::get_logger();
    console->log("Evaluating Model");

    vector<int> pred = this->predict(df);
    vector<int> label = df->data[df->data.size() - 1];
    // Calculate accuracy here
    int count = 0;
    for (int i = 0; i < (int)pred.size(); i++)
        if (pred[i] == label[i])
            count++;

    return (float)count / pred.size();
}