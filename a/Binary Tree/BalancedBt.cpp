#include<bits/stdc++.h>
using namespace std;

bool Display(Node* root)
{
    return Check(root)!=-1;
}
int Check(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lh = Check(root->left);
    int rh = Check(root->right);
    if(lh == -1 or rh == -1) return -1;
    if(abs(lh - rh) > 1)
    return -1;
    return max(lh,rh)+1;
}