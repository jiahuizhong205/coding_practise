#include <algorithm>
//
// Created by zhongjiahui on 26-2-8.
//
/*
给定一个二叉树，判断它是否是 平衡二叉树
平衡二叉树 是指该树所有节点的左右子树的高度相差不超过 1
*/
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int getHeight(TreeNode* root){
        if(root == nullptr) return 0;
        int leftHeight = getHeight(root->left);
        if(leftHeight == -1) return -1;
        int rightHeight = getHeight(root->right);
        if(rightHeight == -1) return -1;
        if(abs(leftHeight - rightHeight) > 1) return -1;
        return std::max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};