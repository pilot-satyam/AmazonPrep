#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size();
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
  int maxi = 0;
  for(int i=0;i<n;i++)
  {
      if(dp1[i] == 1 or dp2[i] == 1) continue; // we cannot have steep
       maxi = max(maxi,dp1[i]+dp2[i]-1);
  }

  return (n-maxi); 
    }
};