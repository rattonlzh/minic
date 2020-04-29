/**
 * @file TreeNode.h
 * @author Liang Zehao
 * @brief TreeNode类定义语法树节点
 * 
 * @version 0.1
 * @date 2020.04.21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef TREENODE_H
#define TREENODE_H
#include <string>
using namespace std;

/**
 * @brief 二叉树的结点类
 * 
 */
struct TreeNode {
    string content;
    TreeNode* left, *right;
    TreeNode(){content = "";}
    TreeNode(string d, TreeNode* l = nullptr, TreeNode* r = nullptr);
    virtual ~TreeNode();
};

inline TreeNode::TreeNode(string d, TreeNode* l, TreeNode* r):content(d), left(l), right(r) {}
inline TreeNode::~TreeNode() {
    if (!left) {
        delete left;
    }
    if (!right) {
        delete right;
    }
}
#endif
