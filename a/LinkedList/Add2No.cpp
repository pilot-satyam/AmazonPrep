#include<bits/stdc++.h>
using namespace std;
struct ListNode{
   int data;
   ListNode* next;
   ListNode(int data)
   {
    this->data = data;
    this->next = NULL;
   }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{   ListNode* dummy = new ListNode();
    ListNode* temp = dummy;
    int carry = 0; //hamesha humko carry 0 nahi banana hai isiliye not in while loop
    while(l1!=NULL or l2!=NULL or carry!=0)
    {
        int sum = 0;
        if(l1)
        {
            sum+=l1->data;
            l1 = l1->next;
        }
        if(l2)
        {
            sum+= l2->data;
            l2 = l2->next;
        }
        sum+=carry;
        carry = sum/10;
        ListNode newNode = new ListNode(sum%10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}
