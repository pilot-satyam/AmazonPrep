#include<bits/stdc++.h>
using namespace std;

int Diameter(Node* root)
{
   int diameter = 0;
   height(root,diameter);
   return diameter;
}

int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lh = height(root->left,diameter);
    int rh = height(root->right,diameter);
    diameter = max(diameter,lh+rh);
    return 1+max(lh,rh);
}

int main()
{

}