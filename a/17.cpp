#include<bits/stdc++.h>
using namespace std;
int mi = 9999999;
void push(stack<int> &s,int a)
{
  if(s.empty()){
      s.push(a);
  }
  else 
  {
      int x = a;
      if(a<mi){
          x = 2*a - mi;
          a = mi;
      }
      s.push(x);
  }
}

bool isFull(stack<int> &s,int n)
{
    if(s.size() == n) return true;
    return false;
}

bool isEmpty(stack<int> &s)
{
    if(s.empty()) return true;
    return false;
}
int pop(stack<int> &s){
    int v = s.top();
    if(v>=mi) s.pop();
    else{
        int y = 2*mi -v;
        s.pop();
        mi = y;
    }
}
int getMin(stack<int> &s)
{
    return mi;
}