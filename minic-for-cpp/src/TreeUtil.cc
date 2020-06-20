/**
 * @file TreeUtil.cc
 * @author Liang Zehao
 * @brief TreeUtil类是一个工具类，用于对TreeNode类进行一些操作如构造树，打印树
 * 
 * @version 0.1
 * @date 2020.04.21
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "TreeUtil.h"

TreeNode* TreeUtil::rootHandle = nullptr;

TreeNode* TreeUtil::getRoot()
{
    return rootHandle;
}

void TreeUtil::setRoot(TreeNode* root)
{
    rootHandle = root;
}

TreeNode *TreeUtil::buildTree(string str)
{
    return new TreeNode(str);
}

void TreeUtil::printTree(TreeNode *root)
{
    printTreeNoWrap(root, 0);
}

TreeNode *TreeUtil::buildTree(string str, vector<TreeNode *> childs)
{
    TreeNode *root = new TreeNode(str);
    root = buildTree(root, childs);
    return root;
}

TreeNode *TreeUtil::buildTree(TreeNode *root, vector<TreeNode *> childs)
{
    // 根节点不存在返回空
    if (nullptr == root)
    {
        return nullptr;
    }
    TreeNode *tmp = root;
    int k = 0;
    // 找到第一个非空孩子节点
    while (k < childs.size() && childs[k] == nullptr)
        ++k;
    // 找不到非空孩子节点
    if (k == childs.size())
    {
        return nullptr;
    }
    // 找到并切换到长子节点
    tmp->left = childs[k];
    tmp = tmp->left;
    // 将兄弟节点连成一条右孩子链
    for (int i = k + 1; i < childs.size(); ++i)
    {
        if (childs[i] == nullptr)
        {
            continue;
        }
        tmp->right = childs[i];
        tmp = tmp->right;
    }
    return root;
}

void TreeUtil::destroyTree(TreeNode *root)
{
    delete root;
}

void TreeUtil::printTreeNoWrap(TreeNode *root, int k)
{
    if (nullptr == root)
    {
        return;
    }

    printTab(k, root->right == nullptr);
    cout << root->content << endl;
    // 没有孩子节点
    if (root->left == nullptr)
    {
        return;
    }
    root = root->left;
    printTreeNoWrap(root, k + 1);
    while (root->right != nullptr)
    {
        root = root->right;
        printTreeNoWrap(root, k + 1);
    }
}

void TreeUtil::printTab(int k, bool end)
{
    while (k > 1)
    {
        cout << "│     ";
        --k;
    }
    if (k > 0)
    {
        if (!end)
        {
            cout << "├── ";
        }
        else 
        {
            cout << "└── ";
        }
    }
}
TreeNode *TreeUtil::mergeTree(TreeNode *t1, TreeNode *t2)
{
    if (nullptr == t1)
    {
        return t2;
    }
    TreeNode *tmp = t1;
    while (tmp->right != nullptr)
    {
        tmp = tmp->right;
    }
    tmp->right = t2;
    return t1;
}