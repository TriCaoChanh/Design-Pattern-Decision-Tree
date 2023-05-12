#include "strategy.h"

Strategy::Strategy() {}
Strategy::~Strategy() {}

/**
 * @brief Strategy Regression
 *
 */
StrategyRegression::StrategyRegression() { console = Logger::get_logger(); }
StrategyRegression::~StrategyRegression() {}

void StrategyRegression::discretize()
{
    console->log("Strategy Regression discretize");
}

void StrategyRegression::normalize()
{
    console->log("Strategy Regression normalize");
}

void StrategyRegression::feature_selection()
{
    console->log("Strategy Regression feature selection");
}

void StrategyRegression::standardize()
{
    console->log("Strategy Regression standardize");
}

/**
 * @brief Strategy Classification
 *
 */
StrategyClassification::StrategyClassification() { console = Logger::get_logger(); }
StrategyClassification::~StrategyClassification() {}

void StrategyClassification::discretize()
{
    console->log("Strategy Classification discretize");
}

void StrategyClassification::normalize()
{
    console->log("Strategy Classification normalize");
}

void StrategyClassification::feature_selection()
{
    console->log("Strategy Classification feature selection");
}

void StrategyClassification::standardize()
{
    console->log("Strategy Classification standardize");
}
