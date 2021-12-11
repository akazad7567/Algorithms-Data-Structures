#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void insertFront(struct Node** headRef,int a){
    Node* newnode=new Node;
    newnode->data=a;
    newnode->next=(*headRef);
    (*headRef)=newnode;
}

void insertEnd(struct Node** headRef,int a){
    Node *newnode=new Node;
    Node *last=*headRef;
    newnode->data=a;
    newnode->next=NULL;
    if(!*headRef){
        *headRef=newnode;
        return;
    }
    while(last->next){
        last=last->next;
    }
    last->next=newnode;
}


void insertAt(struct Node *node,int pos,int val){
    int c=0;

    while(node){
        c++;
        if(c==pos){
            Node* newnode=new Node;
            newnode->data=val;
            newnode->next=node->next;
            node->next=newnode;
            return;
        }
        node=node->next;
    }
}

void deleteAt(struct Node **node, int pos){
    Node* newnode=new Node;
    if(pos==1){
        Node *temp=*node,*prev;
        *node=temp->next;
        return;
    }
    int c=0;
    Node *prev,*temp=*node;
    while(node){
        c++;
        if(c==pos){
            if(!temp->next){
                prev->next=NULL;
                temp=prev;
                return;
            }
            prev->next=temp->next;
            return;
        }
        prev=temp;
        temp=temp->next;
    }

}

void PrintList(struct Node* node){
    while(node){
        cout<<node->data<<' ';
        node=node->next;
    }
}

int main(){
//    freopen("input.txt", "r", stdin);
    Node* head=NULL;
    int a,c=0;
    while(cin>>a){
        c++;
        if(a&1) insertFront(&head,a);
        else insertEnd(&head,a);
        PrintList(head);
        if(c%3==0){
            cout<<"\nenter position and value to insert -> ";
            int x;
            cin>>x>>a;
            if(x==0) insertFront(&head,a);
            else
            insertAt(head,x,a);
            PrintList(head);

            cout<<"\nenter position to delete -> ";
            cin>>x;
            deleteAt(&head,x+1);//for zero base indexing add +1
            PrintList(head);

        }
        cout<<"\n";
    }

    return 0;
}
