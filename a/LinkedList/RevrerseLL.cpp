#include<bits/stdc++.h>
using namespace std;
ListNode* reverseLL(ListNode* head)
{
   ListNode* newHead = NULL;
   while(head!=NULL)
   {
       ListNode* next = head->next;
       head->next = newHead;
       newHead = head;
       head = next;
   }
   return newHead;
}
int main()
{

}