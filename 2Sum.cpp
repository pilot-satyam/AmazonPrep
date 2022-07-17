#include<bits/stdc++.h>
using namespace std;

vector<int> sol(vector<int> &nums,int n,int target)
{
    unordered_map<int,int> m;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(m.find(target - nums[i]) != m.end())
        {
            ans.push_back(m[target - nums[i]]);
            ans.push_back(i);
            return ans; // for the condition that single solution exists
        }
        m[nums[i]] = i; // if the value is not found then storing it in the form of dictionary and maintaining order
    }
    return ans; // to return empty vector if the ans does not exist
}
int main()
{

}