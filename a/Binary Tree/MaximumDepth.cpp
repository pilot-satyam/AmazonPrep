#include<bits/stdc++.h>
using namespace std;

int maxDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int result = 1+max(left,right);
        return result;
    }

int main()
{

}