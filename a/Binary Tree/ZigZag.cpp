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
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
        {
            return result;
        }
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;
        while(!nodesQueue.empty())
        {
            int sz = nodesQueue.size();
            vector<int> row(sz);
            for(int i=0;i<sz;i++)
            {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                //find position to fill the value
                int index = (leftToRight) ? i : (sz-1-i);
                row[index] = node->val;
                if(node->left)
                {
                    nodesQueue.push(node->left);
                }
                if(node->right)
                {
                    nodesQueue.push(node->right);
                }
            }
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};