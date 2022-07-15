#include<bits/stdc++.h>
using namespace std;

vector<int> PrintLIS(vector<int> &a)
{
    int n = a.size();
    vector<int> dp(n,1);
    vector<int> hash(n);
    int maxi = 1;
    int lastIdx = 0;
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++)
    {
        hash[i] = i;
     for(int prev = 0;prev<i;prev++)
     {
        if(a[prev] < a[i]  and 1+dp[prev] > dp[i])
        {
            dp[i] = 1+dp[prev];
            hash[i] = prev;
        }
    }
     if(dp[i] > maxi)
    {
        maxi = dp[i];
        lastIndex = i;
    }
    }
    vector<int> temp;
    temp.push_back(a[lastIndex]);
    while(hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(a[lastIndex]);
    }
    reverse(temp.begin(),temp.end());
    for(auto it : temp)
     {
        cout<<it<<" "; 
     }
 return maxi;
}

int main()
{

}