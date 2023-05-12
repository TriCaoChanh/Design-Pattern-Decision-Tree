#include "preprocessor.h"

Preprocessor::Preprocessor(Strategy *strategy)
{
    this->strategy = strategy;
    console = Logger::get_logger();
}

Preprocessor::~Preprocessor()
{
}

void Preprocessor::preprocessing(bool isRegression, bool isClassification)
{
    if (isRegression && isClassification)
    {
        console->log("A weird problem with both Regression and Classification strategy");
    }
    else if (isRegression)
    {
        this->strategy->discretize();
        this->strategy->normalize();
    }
    else if (isClassification)
    {
        this->strategy->feature_selection();
        this->strategy->standardize();
    }
    else
    {
        console->log("A weird problem with no Regression nor Classification strategy");
    }
}