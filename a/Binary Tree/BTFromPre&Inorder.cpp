#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++)
        {
            inMap[inorder[i]] = i;
        }
        TreeNode* root = AnsTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
        TreeNode* AnsTree(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> &inMap)
        {
            if(preStart > preEnd or inStart > inEnd) return NULL;
            TreeNode* root = new TreeNode(preorder[preStart]);
            int inRoot = inMap[root->val];
            int numsLeft = inRoot - inStart;
            root->left = AnsTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);
            root->right = AnsTree(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
            return root;
        }
};