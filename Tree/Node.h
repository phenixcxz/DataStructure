#ifndef __TREE_NODE_H
#define __TREE_NODE_H
#include "istream"
class TreeNode{
public:
    int val ;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int v = 0,TreeNode * l = NULL,TreeNode * r = NULL):val(v),left(l),right(r){}
};

#endif