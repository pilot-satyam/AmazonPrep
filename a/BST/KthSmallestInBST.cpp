#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int ans = 0;
    int cnt = 0;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
    
    //T.C - O(N) S.C - O(H)
    void inorder(TreeNode* root,int k)
    {
        if(root == NULL) return;
        inorder(root->left,k);
        cnt++; // when the root node is encountered
        if(cnt == k)
        {
            ans = root->val;
            return;
        }
        inorder(root->right,k);
    }
};


int main()
{

}