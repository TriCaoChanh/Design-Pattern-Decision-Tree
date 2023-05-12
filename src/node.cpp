#include "node.h"

int Node::ID = 0;

Node::Node(Node *left, Node *right)
{
    this->id = ID;
    ID++;
    this->left = left;
    this->right = right;
}

Node::~Node()
{
    if (left != nullptr)
        delete left;

    if (right != nullptr)
        delete right;
}
