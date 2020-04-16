#ifndef TREENODE_H
#define TREENODE_H
#include <string>
using namespace std;
class TreeNode {
    string content;
    TreeNode* left, *right;
    TreeNode(string c, TreeNode* l = nullptr, TreeNode* r = nullptr);
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
