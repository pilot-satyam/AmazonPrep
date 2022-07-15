#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i] == s2[j]) return f(i-1,j-1,s1,s2,dp);
    return dp[i][j] = 1+min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
}
int editDistance(string str1, string str2)
{
  int n= str1.size();
  int m = str2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,str1,str2,dp);
}

//Iterative


#include <bits/stdc++.h>

using namespace std;


int editDistance(string& S1, string& S2){
    
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                dp[i][j] = 0+dp[i-1][j-1];
            
            else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    
    return dp[n][m];
    
}


int main() {

  string s1 = "horse";
  string s2 = "ros";

  cout << "The minimum number of operations required is: "<<editDistance(s1,s2);
}