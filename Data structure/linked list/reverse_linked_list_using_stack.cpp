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


Node* Reverse(struct Node* head)
{

    stack<Node*>s;
    Node *temp=head;

    while(temp->next!=NULL)
    {
        s.push(temp);
        temp=temp->next;
    }
    head=temp;

    while(!s.empty())
    {
        temp->next=s.top();
        s.pop();

        temp=temp->next;
    }

    temp->next=NULL;
    return head;
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

    head=Reverse(head);
    print(head);
}


