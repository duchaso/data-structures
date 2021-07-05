#ifndef TREE_H
#define TREE_H
#include <iostream>

struct NodeTree
{
    int data;
    NodeTree* left;
    NodeTree* right;

    NodeTree(int el)
    : data(el), left(nullptr), right(nullptr)
    {}
};


class Tree
{
public:
    NodeTree* root = nullptr;
public:
    void push(int el, NodeTree*& root1);
    void print(NodeTree* root);
    NodeTree* search_(int n);
};

void Tree::push(int el, NodeTree*& root1)
{
    if(root1 == nullptr)
        root1 = new NodeTree(el);
    else
    {
        if(el > root1->data)
            push(el, root1->right);
        else
            push(el, root1->left);
    }
}
void Tree::print(NodeTree* root)
{
    if(root != nullptr)
    {
        print(root->left);
        std::cout << root->data << " ";
        print(root->right);
    }
}

#endif // TREE_H
