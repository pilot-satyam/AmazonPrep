#include<bits/stdc++.h>
using namespace std;

int findMaxDistance(map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &m,BinaryTreeNode<int>* target)
{
    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    map<BinaryTreeNode<int>*,int> vis;
    vis[target] = 1;
    int maxi = 0;
    while(!q.empty())
    {
       int size = q.size();
       int fl = 0;
       for(int i=0;i<size;i++)
       {
           auto node = q.front();
           q.pop();
           if(node->left and !vis[node->left]) //for checking the left
           {
               fl = 1;
               vis[node->left] = 1;
               q.push(node->left);
           }
           if(node->right and !vis[node->right]) //for checking the right
           {
               fl = 1;
               vis[node->right] = 1;
               q.push(node->right);
           }

           if(m[node] and !vis[m[node]]) // for checking the top
           {
               fl = 1;
               vis[m[node]] = 1;
               q.push(m[node]);
           }
       }
       if(fl) maxi++;
    }
    return maxi;
}

BinaryTreeNode<int>* bfsToMapParents(BinaryTreeNode<int>* root,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &m,int start)
{
    q<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>* res;
    while(!q.empty())
    {
        BinaryTreeNode<int>* node = q.front();
        if(node->data == start) return res;
        q.pop();
        if(node->left)
        {
            m[node->left] = node;
            q.push(node->left);
        }
        if(node->right)
        {
            m[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> m;
    BinaryTreeNode<int>* target = bfsToMapParents(root,m,start);
    int maxi = findMaxDistance(m,target); //for burning the adjacent nodes
    return maxi;
}