#include<bits/stdc++.h>
using  namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head->next == NULL)
        {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            slow = slow->next;  
            fast = fast->next->next; 
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow!=NULL)
        {
            if(head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while(head!=NULL)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

//Alternate Way  But S.C - O(N) and T.C O(N)

bool isPalindrome(ListNode* head) {
        vector<int> store;
        while(head!=NULL)
        {
            store.push_back(head->val);
            head = head->next;
        }
        vector<int> res = store;
        reverse(res.begin(),res.end());
        if(res == store) return true;
        return false;
    }