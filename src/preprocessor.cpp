#include "preprocessor.h"
#include <unistd.h>

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
        sleep(1);
        this->strategy->discretize();
        sleep(1);
        this->strategy->normalize();
    }
    else if (isClassification)
    {
        sleep(1);
        this->strategy->feature_selection();
        sleep(1);
        this->strategy->standardize();
    }
    else
    {
        console->log("A weird problem with no Regression nor Classification strategy");
    }
}