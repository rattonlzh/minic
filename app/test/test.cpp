#include<vector>
#include "../src/TreeUtil.h"
#include <iostream>
using namespace std;
int main()
{
    TreeNode *a, *b;
    a = TreeUtil::buildTree("int");
    b = TreeUtil::buildTree("a");
    TreeNode* root = TreeUtil::buildTree("变量声明", {a, b});
    TreeUtil::printTree(root);
    return 0;
}