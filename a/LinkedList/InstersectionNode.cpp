#include<bits/stdc++.h>
using namespace std;

//Best Solution 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
 if(headA == NULL or headB == NULL)
    return NULL;   
 ListNode* a = headA;
 ListNode* b = headB;

 while(a!=b)
 {
    a = (a == NULL) ? headB : a->next;
    b = (b == NULL) ? headA : b->next;
 }   
 return a;
}
// int main()
// {
  
// }

//Using Map By storing the address of the node
//T.C - O(M+N) S.C -O(M)

ListNode* getIntersectionNode(ListNode* headA,ListNode* headB)
{
    unordered_map<ListNode*,bool> m;
    ListNode* a = headA;
    ListNode* b = headB;
    while(a!=NULL)
    {
        m[a] = true;
        a = a->next;
    }
    while(b!=NULL)
    {
        if(m[b] == true)
        return b;
        b = b->next;
    }
    return NULL;
}