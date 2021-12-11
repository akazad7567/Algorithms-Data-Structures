#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};


void insertFront(struct Node** headref,int a)
{
    Node* newnode=new Node;
    newnode->data=a;
    newnode->next=(*headref);
    (*headref)=newnode;
}
//struct LinkedList
//{
//    Node* head;
//    LinkedList() { head = NULL; }
//};
void Reverse(struct Node** head)
{


    Node* cur=*head;
    Node* prv=NULL;
    Node* next=NULL;

    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prv;


        prv=cur;
        cur=next;

    }
    *head=prv;
}

void print(Node* node)
{
    while(node)
    {
        cout<<node->data<<' ';
        node=node->next;
    }
    cout<<endl;
}
int main()
{
    Node* head=NULL;
    int n;
    cin>>n;

    //create a linked list
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        insertFront(&head,a);
    }
    print(head);

    Reverse(&head);
    print(head);
}
