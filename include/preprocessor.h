#ifndef __PREPROCESSOR_H__
#define __PREPROCESSOR_H__

#include "common.h"
#include "logger.h"
#include "strategy.h"

class Preprocessor
{
private:
    Strategy *strategy;

public:
    Logger *console;

public:
    Preprocessor(Strategy *);
    ~Preprocessor();

    void preprocessing(bool isRegression, bool isClassification);
};

#endif