#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

struct Node {
    int value;
    int value_frequency;
    Node *left, *right;
};

#endif // NODE_H_INCLUDED
