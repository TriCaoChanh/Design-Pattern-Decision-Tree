#ifndef __MODEL_H__
#define __MODEL_H__

#include "common.h"
#include "dataframe.h"
#include "node.h"
#include "tree.h"

class Model
{
private:
public:
    Model();
    virtual ~Model();

    virtual void fit(Dataframe* df) = 0;
    virtual vector<int> predict(Dataframe *df) = 0;
    virtual float evaluate(Dataframe *df) = 0;
};

/**
 * @brief Adapter for DecisionTree class
 * 
 */
class DecisionTreeAdaptor : public Model
{
private:
    DecisionTree *tree_;

public:
    DecisionTreeAdaptor();
    ~DecisionTreeAdaptor();

    void fit(Dataframe *df) override;
    vector<int> predict(Dataframe *df) override;
    virtual float evaluate(Dataframe *df) override;
};


/**
 * @brief This is not yet implemented, for example purpose only
 * 
 */
class LogisticsRegressionAdaptor : public Model
{
private:

public:
    LogisticsRegressionAdaptor();
    ~LogisticsRegressionAdaptor();

    void fit(Dataframe *df) override;
    vector<int> predict(Dataframe *df) override;
    virtual float evaluate(Dataframe *df) override;
};

#endif