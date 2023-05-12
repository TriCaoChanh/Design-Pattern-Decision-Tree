#ifndef __DATAFRAME_H__
#define __DATAFRAME_H__

#include "common.h"
#include "logger.h"
#include "file_parser.h"

class Dataframe
{
private:
    vector<vector<double>> data;
    vector<double> Min;
    vector<double> Max;
    vector<double> Mean;
    vector<double> Variance;
private:
    void statistics_();

public:
    vector<string> columns;
    pair<int, int> shape;

public:
    Dataframe();
    ~Dataframe();

    static Dataframe* read_csv(string);

    vector<double> operator[](int);
    double min(int);
    double max(int);
    double mean(int);
    double variance(int);
    double std(int);

    void collect(int);
    void describe();
};

#endif