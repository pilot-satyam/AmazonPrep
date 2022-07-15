#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node *prev,*next;
Node(int d)
{
    this->data = d;
    this->prev = NULL;
    this->next = NULL;
}
~Node()
{
    int val = this->data;
    if(next!=NULL)
    {
        delete next;
        next = NULL;
    }
    cout<<"Memory free for node with data"<<data<<"";
}
};
//Traversing the Linked LIst
void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}
//Length of the LInked List
int GetLength(Node* head)
{
    Node* temp = head;
    int len = 0;
    while(temp!=NULL)
    { 
        len++;   
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head,int d)
{
    if(head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail,int d)
{
    if(tail == NULL)
    {
         Node* temp = new Node(d);
         tail = temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* head,Node* &tail,int position,int d)
{
    if(position == 1)
    {
        insertAtHead(head,d);
    }

        Node* temp = head;
        int cnt = 1;

    while(cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }
    //insert at the end
    if(temp->next == NULL)
    {
        InsertAtTail(head,d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next  = nodeToInsert;
    nodeToInsert->prev = temp;
}

void DeleteNode(Node* head,int position)
{
    if(position == 1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt<position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
Node* node1 = new Node(10);
Node* head = node1;
Node* tail = node1;
print(head);
insertAtHead(head,11);
insertAtHead(head,34);
insertAtHead(head,12);
insertAtTail(tail,25);
print(head);
insertAtPosition(head,tail,2,100);
insertAtPosition(head,tail,4,50);
insertAtPosition(head,tail,1,40);
print(head);
}