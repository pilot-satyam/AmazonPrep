#include<bits/stdc++.h>
using namespace std;

bool checkPossible(string &s1,string &s2)
{
    if(s1.size() != s2.size()+1) return false;
    int first = 0;
    int second = 0;
    while(first < s1.size())
    {
        if(s1[first] == s2[second]) 
        {
            first++;
            second++;
        }
        else
        {
            first++;
        }
    }
    if(first == s1.size() and second == s2.size())
    return true;
return false;
}

static bool comp(string &s1,string &s2)
{
    return s1.size() < s2.size(); // sorting on basis of length
}

int LongestStringChain(vector<string> &words)
{
 int n = words.size();
 sort(words.begin(),words.end(),comp); // we are sorting here because we want substring and not subsequence.
 vector<int> dp(n,1);
 int maxi = 1;
 for(int i=0;i<n;i++)
 {
    for(int prev = 0;prev<i;prev++)
    {
        if(checkPossible(words[i],words[prev]) and 1+dp[prev] > dp[i])
        {
            dp[i] = 1+dp[prev];
        }
    }
    if(dp[i] > maxi)
    {
        maxi = dp[i];
    }
 }
 return maxi;
}

int main()
{

}