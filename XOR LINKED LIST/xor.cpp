#include <bits/stdc++.h> 
#include <inttypes.h> 
using namespace std; 

class Node 
{ 
	public: 
        int data; 
        Node* link; 
}; 

Node* XOR (Node *x, Node *y) 
{ 
	return (Node*)((uintptr_t)(x) ^ (uintptr_t)(y)); 
} 

void insertBegin(Node **head, int data) 
{ 
	Node *new_node = new Node(); 
	new_node->data = data; 

	new_node->link = *head; 

	
	if (*head != NULL) 
	{ 		
		(*head)->link = XOR(new_node, (*head)->link); 
	} 

	*head = new_node; 
}

void insertEnd(Node **head,int data) {

    Node *curr = *head; 
	Node *prev = NULL; 
	Node *next; 

    while (curr != NULL) 
	{ 
		next = XOR (prev, curr->link); 
		prev = curr; 
		curr = next; 
	} 

    Node *new_node = new Node(); 
	new_node->data = data; 

    // cout<<prev->data<<endl;
    prev->link = XOR(new_node,prev->link);

    new_node->link = XOR(NULL,prev);

}


void printList (Node *head) 
{ 
	Node *curr = head; 
	Node *prev = NULL; 
	Node *next; 

	while (curr != NULL) 
	{ 
		
		cout<<curr->data<<" "; 

		
		next = XOR (prev, curr->link); 
		prev = curr; 
		curr = next; 
	} 
    cout<<endl;
} 

// Driver code 
int main () 
{ 
	Node *head = NULL; 
    int n,data,i,ch;
    cin>>n;
    cout<<"Enter data to insert at begin"<<endl;
    for(i=0;i<n;i++) {
        cin>>data;
        insertBegin(&head,data);
    }
    cout<<"List is ";
    printList (head); 
    cout<<"Enter data to insert at end"<<endl;
    cin>>data;
    insertEnd(&head,data);
    cout<<"Updated list ";
	printList (head); 

	return (0); 
} 
