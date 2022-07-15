#include<bits/stdc++.h>
using namespace std;

//T.C -O(N) S.C -O(N)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int curr = root->val;
        if(p->val > curr and q->val >curr) return lowestCommonAncestor(root->right,p,q);
        if(p->val < curr and q->val < curr) return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};

//Iterative
//T.C - O(N) S.C - O(1)

 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        while(root!=NULL)
        {
            int curr = root->val;
            if(p->val > curr and q->val > curr) root = root->right;
            else if(p->val < curr and q->val < curr) root = root->left;
            else 
                return root;
        }
        return NULL;
    }