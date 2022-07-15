#include<bits/stdc++.h>
using namespace std;
/*
 Definition for a binary tree node.
 */ struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!= postorder.size()) return NULL;
        map<int,int> pm;
        for(int i=0;i<inorder.size();i++)
        {
            pm[inorder[i]] = i;
        }
        TreeNode* root = AnsTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,pm);
        return root;
    }
    TreeNode* AnsTree(vector<int> &inorder,int inStart,int inEnd,vector<int> &postorder,int pStart,int pEnd,map<int,int> &pm)
    {
        if(inStart > inEnd or pStart > pEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[pEnd]);
        int inRoot = pm[root->val];
        //int inRoot = pm[postorder[pEnd]];
        int numsLeft = inRoot - inStart;
        //new left subtree inorder
        root->left = AnsTree(inorder,inStart,inRoot-1,postorder,pStart,pStart+numsLeft-1,pm);
        
        //new right right subtree
        
        root->right = AnsTree(inorder,inRoot+1,inEnd,postorder,pStart+numsLeft,pEnd-1,pm);
        return root;
    }
};
int main()
{
  int n;
  cin>>n;
  vector<int> inorder(n);
  vector<int> postorder(n);
  for(int i=0;i<n;i++)
  {
      cin>>inorder[i];
      cin>>postorder[i];
  }
  Solution obj;
  cout << obj.buildTree(inorder,postorder);
}