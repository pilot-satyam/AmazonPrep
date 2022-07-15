#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int val;
   TreeNode *left,*right;
   TreeNode(int val)
   {
    this->val = val;
    left = NULL;
    right = NULL;
   }
};

TreeNode* InorderSuccessor(TreeNode* root,TreeNode* p)
{
    TreeNode* successor = NULL;
    if(root == NULL) return NULL;
    while(root!=NULL)
    {
        if(root->val <= p->val)
        {
            root = root->right;
        }
        else
        {
            successor = root;
            root = root->left;
        }
    }
    return root;
}

int main()
{

}