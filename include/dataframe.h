#ifndef __DATAFRAME_H__
#define __DATAFRAME_H__

#include "common.h"
#include "logger.h"
#include "file_parser.h"

class Dataframe
{
private:
    vector<int> Min;
    vector<int> Max;
    vector<float> Mean;
    vector<float> Variance;
private:
    void statistics_();

public:
    vector<vector<int>> data;
    vector<string> columns;
    pair<int, int> shape;

public:
    Dataframe();
    ~Dataframe();

    static Dataframe* read_csv(string);

    vector<int> operator[](int);
    double min(int);
    double max(int);
    double mean(int);
    double variance(int);
    double std(int);

    void collect(int);
    void describe();
};

#endif