/**
 * @file: TreeUtil.h
 * @brief: TreeUtil类是一个工具类，用于对TreeNode类进行一些操作如构造树，打印树
 * @version: 0.1
 * @author: Liang Zehao
 * @date: 2020.04.21
 */
#ifndef TREEUTIL_H
#define TREEUTIL_H
#include "TreeNode.h"

class TreeUtil
{
public:

    /**
     * 传入字符串str和孩子节点childs, 构造以childs为孩子节点、根节点的数据是str的树，返回树的根节点
     * @param str 根节点的数据
     * @param childs 孩子节点
     * @param n 节点数
     * @return 树的根节点
     */
    static TreeNode* buildTree(string str, TreeNode* childs[], int n);
    
    /**
     * 打印语法树
     * @param root:语法树的根节点
     */
    static void printTree(TreeNode *root);

    /**
     * 根据传入的根节点和孩子节点构造多叉树
     * @param root 根节点 
     * @param childs 孩子节点 孩子节点数
     */
    static void buildTree(TreeNode *root, TreeNode*childs[], int n);
    /**
     * 销毁树
     * @param root 被销毁的树的根节点
     */
    static void destroyTree(TreeNode *root);
};

#endif
