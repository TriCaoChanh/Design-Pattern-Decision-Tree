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
    console->log("Regression discretize");
}

void StrategyRegression::normalize()
{
    console->log("Regression normalize");
}

void StrategyRegression::feature_selection()
{
    console->log("Regression feature selection");
}

void StrategyRegression::standardize()
{
    console->log("Regression standardize");
}

/**
 * @brief Strategy Classification
 *
 */
StrategyClassification::StrategyClassification() { console = Logger::get_logger(); }
StrategyClassification::~StrategyClassification() {}

void StrategyClassification::discretize()
{
    console->log("Classification discretize");
}

void StrategyClassification::normalize()
{
    console->log("Classification normalize");
}

void StrategyClassification::feature_selection()
{
    console->log("Classification feature selection");
}

void StrategyClassification::standardize()
{
    console->log("Classification standardize");
}
