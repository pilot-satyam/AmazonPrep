#include<bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256
//O(N^2)
int solve(string s)
{
    int n = s.size();
    int res = 0;
    vector<bool> vis(256);
    for(int i=0;i<n;i++)
    {
      for(int j=i;j<n;j++)
      {
          if(vis[s[j]] == true) break; // check if the character is already visited,if visited then break through it and again start
          else{
              res = max(res,j-i+1);
              vis[s[j]] = true;
          }
      }
      vis[s[i]] = false; // removing the first character of the previous window
    }
    return res;
}

int OptimizedSolve(string s)
{
    int n = s.size();
    int res = 0;
    vector<int> lastIndex(NO_OF_CHARS,-1);
    int i = 0;//initialising the start of current window
    for(int j=0;j<n;j++)
    {
      i = max(i,lastIndex[s[j]]+1);
      res = max(res,j-i+1);
      lastIndex[s[j]] = j;
    }
    return res;
}

int main()
{
  string s;
  cin>>s;
  cout<<OptimizedSolve(s);
}