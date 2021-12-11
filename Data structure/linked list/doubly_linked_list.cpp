// A complete working C++ program to
// demonstrate all insertion methods
#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
	public:
	int data;
	Node* next;
	Node* prev;
};

/* Given a reference (pointer to pointer)
to the head of a list
and an int, inserts a new node on the
front of the list. */
void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);
	new_node->prev = NULL;

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}



// This function prints contents of
// linked list starting from the given node
void printList(Node* node)
{
	Node* last;
	cout<<"\nTraversal in forward direction \n";
	while (node != NULL)
	{
		cout<<" "<<node->data<<" ";
		last = node;
		node = node->next;
	}

	cout<<"\nTraversal in reverse direction \n";
	while (last != NULL)
	{
		cout<<" "<<last->data<<" ";
		last = last->prev;
	}
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        push(&head,a);
    }


	cout << "Created DLL is: ";
	printList(head);

	return 0;
}


