#include<bits/stdc++.h>
using namespace std;

pair dfs<Node* root,int count>
{
    if(root == NULL) return {0,0};
    auto left = dfs(root->left,count);
    auto right = dfs(root->right,count);
    int cnt = 1 + left.second + right.second;
    int sum = left.first+right.first;
    if(sum/count == root->val)
    count++;
    return {sum,cnt}; 
}

int avgOfSubtree(Node* root)
{
    int cnt = 0;
    dfs(root,cnt);
    return cnt;
}
int main()
{

}