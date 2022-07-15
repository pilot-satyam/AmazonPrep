//IN LESS Than O(N) T.C
#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int findHeightLeft(TreeNode* root)
    {
        int hgt = 0;
        while(root)
        {
            hgt++;
            root = root->left;
        }
        return hgt;
    }

    int findHeightRight(TreeNode* root)
    {
        int hgt = 0;
        while(root)
        {
            hgt++;
            root= root->right;
        }
        return hgt;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        if(lh == rh) return (1<<lh) - 1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};