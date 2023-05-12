#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include "common.h"
#include "Logger.h"

class Strategy
{
public:
    Strategy();
    virtual ~Strategy();

    virtual void normalize() = 0;
    virtual void standardize() = 0;
    virtual void feature_selection() = 0;
    virtual void discretize() = 0;
};

class StrategyRegression : public Strategy
{
public:
    Logger *console;

public:
    StrategyRegression();
    ~StrategyRegression();

    void normalize() override;
    void standardize() override;
    void feature_selection() override;
    void discretize() override;
};

class StrategyClassification : public Strategy
{
public:
    Logger *console;

public:
    StrategyClassification();
    ~StrategyClassification();

    void normalize() override;
    void standardize() override;
    void feature_selection() override;
    void discretize() override;
};

#endif