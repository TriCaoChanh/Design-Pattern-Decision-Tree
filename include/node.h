#ifndef __NODE_H__
#define __NODE_H__

#include "common.h"

class Node
{
private:
    int id;
    Node *left;
    Node *right;

private:
    static int ID;

public:
    Node(Node *, Node *);
    ~Node();

    // void print_node();
};

#endif