/**
 * @file: TreeUtil.cc
 * @brief: TreeUtil类是一个工具类，用于对TreeNode类进行一些操作如构造树，打印树
 * @version: 0.1
 * @author: Liang Zehao
 * @date: 2020.04.21
 */
#include "TreeUtil.h"

/**
 * 打印语法树
 * @param root 语法树的根节点
 */
void TreeUtil::printTree(TreeNode *root)
{
    //TODO:打印语法树
}

/**
 * 传入字符串str和孩子节点childs, 构造以childs为孩子节点、根节点的数据是str的树，返回树的根节点
 * @param str 根节点的数据
 * @param childs 孩子节点
 * @param n 节点数
 * @return 树的根节点
 */
TreeNode* TreeUtil::buildTree(string str, TreeNode *childs[], int n)
{
    TreeNode *root = new TreeNode(str);
    buildTree(root, childs, n);
    return root;
}

/**
 * 根据传入的根节点root和孩子节点构造以root为根节点的多叉树
 * @param root 根节点 
 * @param childs 孩子节点
 * @param n 孩子节点数
 */
void TreeUtil::buildTree(TreeNode *root, TreeNode *childs[], int n)
{
    root->left = childs[0]; // 长子节点
    root = root->left;
    // 将兄弟节点连成一条右孩子链
    for (int i = 1; i < n; ++i)
    {
        root->right = childs[i];
        root = root->right;
    }
}
/**
 * 销毁树
 * @param root 被销毁的树的根节点
 */
void TreeUtil::destroyTree(TreeNode *root)
{
    delete root;
}