#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data) //jab bhi new node create hogi to usme data daldo aur address NULL kardo isiliye const. use ho rha hai
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if(this->next !=NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"memory freed for the data"<<data<<endl;
    }
};

void InsertAtHead(Node* &head,int d)
{
   //jab bhi koi data aaye then create new node
   Node* temp = new Node(d);
   temp->next = head;
   head = temp;
}

void InsertAtTail(Node* &tail,int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void InsertAtMiddle(Node* &head,int position,int d)
{
    if(position == 1)
    {
        InsertAtHead(head,d);
        return;
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
    temp->next = nodeToInsert;
}

void delete(int position,Node* &head)
{
    if(position == 1)
    {
        Node* temp = head;
        head = head->next;
        //memory free the start node
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt =1;
        while (cnt<=position)
        {
        prev = curr;
        curr = curr->next;
        cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
  Node* node1 = new Node(10);
//   cout<<node1->data<<endl;
//   cout<<node1->next<<endl;

  Node* head = node1;
  Node* tail = node1;
  print(head);
  InsertAtTail(tail,12);
  InsertAtTail(tail,56);
  InsertAtMiddle(head,2,69);
 // InsertAtHead(head,20);
  print(head);
}