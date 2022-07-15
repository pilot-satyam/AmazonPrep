#include<bits/stdc++.h>
using namespace std;

//T.c - O(n) 
//S.C - O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL or head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next and fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};

int main()
{

}