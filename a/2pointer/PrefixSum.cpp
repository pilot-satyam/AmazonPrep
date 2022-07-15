#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5] = {1,2,3,4,5};
    int n = 5;
    int pre[n+1];
    pre[0] = 0;
    for(int i=1;i<=n;i++)
    {
        pre[i] = pre[i-1] + a[i-1]; //adding present element with previous element prefix is 1 based idx and a is 0 based idx
        // cout<<pre[i]<<" ";
    }
    
    for(int i=0;i<=n;i++)
    {
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    
    int i =2; //to compute the sum between 3 & 4
    int j =3;
    cout<<pre[j+1] - pre[i]; //j+! because in prefix array it is "index+1" and "i" remains same bcoz we want 
                             //sum till 3
}