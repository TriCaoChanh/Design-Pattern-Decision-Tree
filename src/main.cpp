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
    Parser *parser = new CSV_Parser();
    parser->read_file(FILE_PATH);
    parser->print_file();
    delete parser;
}

void testDataframe(){
    Logger *console = Logger::get_logger();

    Dataframe *df = Dataframe::read_csv(FILE_PATH);

    console->log("Dataframe shape: (" + to_string(df->shape.first) + ", " + to_string(df->shape.second) + ")");

    console->log("\nStatistics");
    df->describe();

    console->log("\nHead");
    df->collect(5);

    delete df;
}

void testPreprocessor()
{
    Logger *console = Logger::get_logger();

    // REGRESSION STREATEGY
    console->log("Preprocessing Strategy for Regression");
    Strategy *regression_strategy = new StrategyRegression();
    Preprocessor regression_preprocessor(regression_strategy);

    regression_preprocessor.preprocessing(true, false);

    // CLASSIFICATION STRATEGY
    console->log("-----");
    console->log("Preprocessing Strategy for Classification");
    Strategy *classification_strategy = new StrategyClassification();
    Preprocessor classification_preprocessor(classification_strategy);

    classification_preprocessor.preprocessing(false, true);

    delete regression_strategy;
    delete classification_strategy;
}

void testDecisionTree() {
    Logger *console = Logger::get_logger();
    
    Model *decision_tree = new DecisionTreeAdaptor();
    Dataframe *df = Dataframe::read_csv(FILE_PATH);

    decision_tree->fit(df);
    float accuracy = decision_tree->evaluate(df);

    console->log("Accuracy: " + to_string(accuracy));

    delete decision_tree;
    delete df;
}

int main(int argc, char *argv[])
{
    int input = atoi(argv[1]);
    if (input == 0)
        testLogger();
    else if (input == 1)
        testParser();
    else if (input == 2)
        testDataframe();
    else if (input == 3)
        testPreprocessor();
    else if (input == 4)
        testDecisionTree();

    return 0;
}