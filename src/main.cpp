#include "common.h"

#include "logger.h"
#include "node.h"
#include "tree.h"
#include "preprocessor.h"
#include "strategy.h"
#include "dataframe.h"
#include "file_parser.h"
#include "model.h"


void testLogger()
{
    Logger *console = Logger::get_logger();
    console->log("Log successfully!");
}

void testParser()
{
    CSV_Parser *parser = new CSV_Parser();
    parser->read_file(FILE_PATH);
    parser->print_file();
    delete parser;
}

void testDataframe(){
    Logger *console = Logger::get_logger();

    Dataframe *df = Dataframe::read_csv(FILE_PATH);

    console->log("Dataframe shape: (" + to_string(df->shape.first) + ", " + to_string(df->shape.second) + ")");

    console->log("Statistics");
    df->describe();

    console->log("Head");
    df->collect(5);

    delete df;
}

void testPreprocessor()
{
    // Logger *console = Logger::get_logger();

    Strategy *regression_strategy = new StrategyRegression();
    Preprocessor preprocessor(regression_strategy);

    preprocessor.preprocessing(true, false);
}

void testDecisionTree() {
    Logger *console = Logger::get_logger();
    
    Model *decision_tree = new DecisionTreeAdaptor();
    Dataframe *df = Dataframe::read_csv(FILE_PATH);

    decision_tree->fit(df);
    float accuracy = decision_tree->evaluate(df);

    console->log("Accuracy: " + to_string(accuracy));
}

int main()
{
    testDecisionTree();

    return 0;
}