#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if(this->next!=NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for node with data"<<value<<endl; 
    }
};

void InsertNode(Node* tail,int d,int element)
{
    if(tail == NULL)
    {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        //non empty list
       Node* curr = tail;
       while(curr->data!=element)
       {
           curr = curr->next;
       }

       //element found and currrent uske upar hai,
       Node* temp = new Node(d);
       temp->next = curr->next;
       curr->next = temp;
    }
}

void print(Node* tail)
{
    Node* temp = tail; //storing tail ki value in temp
    if(tail == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    do
   {
       cout<<tail->data<<" ";
       tail = tail->next;
   }while(tail!=temp);
    cout<<" ";
}

void DeleteNode(Node* tail,int value)
{
    //empty list
    if(tail == NULL) cout<<"List is Empty";
    return;
    else{
          Node* prev = tail;
          Node*curr = prev->next;
          while(curr->data!=value)
          {
              prev = curr;
              curr = curr->next;
          }
         prev->next = curr->next;
         //if only one node in LL
         if(curr == prev)
         {
             tail = NULL;
         }
        else if(tail == curr)
         {
             tail = prev;
         }
         curr->next = NULL;
         delete curr;   
    }
}

int main()
{
Node* tail = NULL;  
//empty list
InsertNode(tail,5,3);
print(tail);
InsertNode(tail,3,5);
print(tail);
InsertNode(tail,5,7);
print(tail);
}