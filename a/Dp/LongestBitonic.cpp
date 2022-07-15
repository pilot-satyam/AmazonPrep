#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int> &a,int n)
{
  vector<int> dp1(n,1);
  for(int i=0;i<n;i++)
  {
    for(int prev =0;prev<i;prev++)
    {
        if(a[i] > a[prev] and dp1[i] < 1+dp1[prev])
        {
            dp1[i] = 1 + dp1[prev];
        }
    }
    // if(maxi > dp[i])
    // {
    //     maxi = dp[i];
    // }
  }

vector<int> dp2(n,1);
  for(int i=n-1;i>=0;i--)
  {
    for(int prev =n-1;prev>i;prev--)
    {
        if(a[i] > a[prev] and dp2[i] < 1+dp2[prev])
        {
            dp2[i] = 1 + dp2[prev];
        }
    }
  }
  int maxi = 1;
  for(int i=0;i<n;i++)
  {
    maxi = max(maxi,dp1[i]+dp2[i]-1);
  }

  return maxi;
}

int main()
{

}