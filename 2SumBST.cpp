#include<bits/std++.h>
using namespace std;

struct TreeNode
{
     int data;
     TreeNode *left,*right;
     TreeNode(int val)
     {
        data = val;
        left = NULL;
        right = NULL;
     }
};

//Optimized Approach
 // T.C - O(N)
 //S.C - 2*O(H)

class BSTIterator
{
  stack<TreeNode*> st;
  //before true -> previous element
  //befor false ->next element
  bool before = true;  
  public:
  BSTIterator(TreeNode* root,bool isBefore)
  {
    before = isBefore;
    pushALL(root);
  }
  bool hasNext()
  {
    return !st.empty();
  }
  int next()
  {
    TreeNode* node = st.top();
    st.pop();
    if(!before) pushALL(node->right);
    else pushALL(node->left);
    return node->val;
  }

  void pushALL(TreeNode* root)
  {
    while(root!=NULL)
    {
        st.push(root);
        if(before == true){
        root = root->right;
        }
        else{
            root = root->left;
        }
    }
  }
};

class Solution{
public:
bool findTarget(TreeNode* root,int k)
{
      if(!root) return false;
      BSTIterator l(root,false);
      BSTIterator r(root,true);
      int i = l.next();
      int j = r.next(); // we are doing this to optimize code as it will point only to previous elements
      while(i<j)
      {
        if(i+j == k) return true;
        else if(i+j<k) i = l.next();
        else j = r.next();
      }
      return false;
}
};


// Alternate Approach
//T.C  - O(N)+O(N)
//S.C  - O(N)

class Solution {
public:
    
    void inorder(TreeNode* root,vector<int> &inorderSt)
    {
        if(root == NULL) return;
        inorder(root->left,inorderSt);
        inorderSt.push_back(root->val);
        inorder(root->right,inorderSt);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderSt;
        inorder(root,inorderSt);
        int i = 0;
        int n = inorderSt.size();
        int j = n-1;
        while(i<j)
        {
           // if(i == j) break;
           if(inorderSt[i] + inorderSt[j] == k) return true;
            else if(inorderSt[i] + inorderSt[j] < k)
            {
                i++;
            }
            else if(inorderSt[i] + inorderSt[j] > k)
            {
                j--;
            }
            else
                break;
        }
        return false;
    }
};

int main()
{

}