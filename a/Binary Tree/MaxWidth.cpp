#include<bits/stdc++.h>
using namespace std;

int MaxWidthOfBT(Node* root)
{
    if(!root) return 0;
    int ans = 0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        //Now since we need to indexing we traverse till the size of b.t hence q sz is imp
        int size = q.size();
        // Node* node = q.front().first;
        int minIdx = q.front().second();
        for(int i=0;i<size;i++)
        {
            Node* node = q.front().first;
            q.pop();
            int first,last;
            long cur_idx = q.front().second - minIdx;
            if(i==0) cur_idx = first;
            if(i == size-1) cur_idx = last;
            if(node->left)
            {
                q.push({node->left,cur_idx*2+1});
            }
            if(node->right)
            {
                q.push({node->right,cur_idx*2+2});
            }
        }
            ans = max(ans,last-first+1);
    }
    return ans;
}
int main()
{

}