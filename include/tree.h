#ifndef __TREE_H__
#define __TREE_H__

#include "common.h"
#include "node.h"

struct TwoDataFrame
{
    DataFrame pres;
    DataFrame abs;
};

// instantiate the node in the heap, then don't need to explicitly allocate member
// variables memory in the heap
class DecisionTree
{
    // Access specifier
public:
    // at some point need to make private and expose using getters and setters
    Node *rootP;
    // DataFrame trainingData;

    DecisionTree(const DataFrame &);

    ~DecisionTree();

    DecisionTree *DeepCopy()
    {
        // READ ABOUT DEEP AND SHALLOW COPIES

        // copy stuff
        return this;
    }

    DecisionTree *ShallowCopy()
    {
        // READ ABOUT DEEP AND SHALLOW COPIES

        // copy stuff
        return this;
    }

    // Traverse tree
    void traverseTree() const;
    static TwoDataFrame splitData(const DataFrame &dataBefore, int feature, int category);
    static void constructTree(Node *nodeP);
    std::vector<int> predict(const DataFrame&);
    void deleteChildren(Node *nodeP);
    static int recursivelyPredict(Node *nodeP, std::vector<int> observations);
};

#endif