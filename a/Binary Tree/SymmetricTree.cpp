#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 /
 */
class Solution {
public:
    
    int symmetry(TreeNode*p,TreeNode*q)
    {
        if(p == NULL or q == NULL)
        {
            return (p==q);
        }
        return(p->val == q->val) and symmetry(p->left,q->right) and symmetry(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(symmetry(root->left,root->right))return true;
        return false;
    }
};