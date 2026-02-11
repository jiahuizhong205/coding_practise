//
// Created by zhongjiahui on 26-2-9.
//
/*

给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。如果有多种构造方法，请你返回任意一种。

如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。

*/

//先使用中序遍历得到辅助数组（升序结果，因为二叉搜索树的性质），接下来数组左一半作为左子树，右一半作为右子树，即可平衡
#include <stack>
#include<vector>
using namespace std;
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while(!s.empty()|| p != nullptr) {
            while (p!=nullptr) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
    TreeNode* constructTree(const vector<int>& nums,int left,int right) {
        if(left>right) {
            return nullptr;
        }
        int mid = (left+right)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = constructTree(nums,left,mid-1);
        root->right = constructTree(nums,mid+1,right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> res = inorderTraversal(root);
        return constructTree(res,0,res.size()-1);
    }
};