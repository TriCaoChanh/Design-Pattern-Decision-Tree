#include "common.h"

#include "logger.h"
#include "node.h"
#include "tree.h"
#include "preprocessor.h"
#include "strategy.h"
#include "dataframe.h"

void testLogger()
{
    Logger *console = Logger::get_logger();
    console->log("Log successfully!");
}

void testTrainer()
{
    // Logger *console = Logger::get_logger();

    Strategy *regression_strategy = new StrategyRegression();
    Preprocessor optimizer(regression_strategy);

    optimizer.preprocessing(true, false);
}

void testDataframe(){
    Logger *console = Logger::get_logger();

    Dataframe* df = Dataframe::read_csv("creditcard.csv");

    console->log("Dataframe shape: (" + to_string(df->shape.first) + ", " + to_string(df->shape.second) + ")");

    console->log("Statistics");
    df->describe();

    console->log("Head");
    df->collect(5);

    delete df;
}

int main()
{
    testDataframe();

    return 0;
}