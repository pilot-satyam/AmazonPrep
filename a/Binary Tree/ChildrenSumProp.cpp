#include<bits/stdc++.h>
using namespace std;

struct Node()
{
    Node *left,*right;
    int data;
}

void changeTree(Node* root)
{
   if(root == NULL) return;
   int childSum = 0;
   if(root->left) childSum+=root->left->data;
   if(root->right) childSum+=root->right->data;
   if(childSum >= root->data) root->data = childSum;
   else
   {
      if(root->left) root->left->data = root->data;
      else if(root->right) root->right->data = root->data;
   }
   changeTree(root->left);
   changeTree(root->right);
   int tot = 0;
   if(root->left) tot+=root->left->data;
   if(root->right) tot+=root->right->data;
   if(root->left or root->right) root->data = tot;
}