#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
}

bool isvalid(TreeNode* root, long min, long max){
		if (root ==NULL) return true;
		if(root->val <= min || root->val >= max)  return false;
		return(isvalid(root->left,min,root->val) && isvalid(root->right,root->val, max));
	}


	bool isValidBST(TreeNode* root) {
		return isvalid(root, LONG_MIN , LONG_MAX );
	}

int main()
{

}