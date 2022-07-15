#include<bits/std++.h>
using namespace std;

//The basic ides is to just copy the next node into the previous node
//Since the head is not given

struct ListNode{
     int val;
     ListNode* next;
     ListNode(int val)
     {
        this->val = val;
        this->next = NULL;
     }
};

ListNode* DeleteNode(ListNode* node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}

int main()
{

}