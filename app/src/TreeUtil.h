#ifndef TREEUTIL_H
#define TREEUTIL_H
#include "TreeNode.h"
class TreeUtil
{
public:
    TreeUtil() {}
    static void printTree(TreeNode *root);
    static void buildTree(TreeNode *root, TreeNode *childs[]);
    static void destroyTree(TreeNode *root);
};


#endif

