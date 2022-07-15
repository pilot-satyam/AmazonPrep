#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n = a.size();
    vector<int> dp(n,1);
    vector<int> hash(n);
    int maxi = 1;
    int lastIndex = 0;
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++)
    {
        hash[i] = i;
     for(int prev = 0;prev<i;prev++)
     {
        if(a[i] % a[prev] == 0 and 1+dp[prev] > dp[i])
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
        return temp;
    }
};

int main()
{

}