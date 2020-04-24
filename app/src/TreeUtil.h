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
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class TreeUtil
{
public:
    /**
     * @brief 构造一个以str为内容的根节点
     * 
     * @param str 根节点的内容
     * @return TreeNode* 返回的根节点
     */
    static TreeNode *buildTree(string str);
    /**
     * @brief 传入字符串str和孩子节点childs, 构造以childs为孩子节点、根节点的数据是str的树，返回树的根节点
     * @param str 根节点的数据
     * @param childs 孩子节点
     * @return 树的根节点
     */
    static TreeNode *buildTree(string str, vector<TreeNode *> childs);

    /**
     * 打印语法树，输出到标准输出流，末尾含换行
     * @param root:语法树的根节点
     */
    static void printTree(TreeNode *root);

    /**
     * @brief 根据传入的根节点和孩子节点构造多叉树，如果根节点为空则返回空；孩子节点中的空节点会被忽略
     * @param root 根节点 
     * @param childs 孩子节点 孩子节点数
     * @return 多叉树的根节点
     */
    static TreeNode *buildTree(TreeNode *root, vector<TreeNode *> childs);

    /**
     * 销毁树
     * @param root 被销毁的树的根节点
     */
    static void destroyTree(TreeNode *root);

    /**
     * @brief 合并两棵树，两棵树的根节点互为兄弟节点
     * 
     * @param t1 被合并树1的根节点
     * @param t2 被合并树2的根节点
     * @return TreeNode* 
     */
    static TreeNode *mergeTree(TreeNode *t1, TreeNode *t2);

private:
    /**
     * @brief 打印语法树，末尾没有换行 
     * 
     * @param root 
     */
    static void printTreeNoWrap(TreeNode *root);
};

#endif
