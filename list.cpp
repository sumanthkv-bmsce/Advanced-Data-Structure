#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *right;
};

typedef struct node* NODE;
NODE root=NULL;

NODE newNode() {

    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->right = NULL;
    return temp;

}

void insertAfter(int data) {

    NODE temp;
    NODE prev = root;
    temp = newNode();
    temp->data = data;
    if(root==NULL) {
        root = temp;
        return;
    }

    while(prev->right!=NULL) {
        prev = prev->right;
    }

    prev->right = temp;
}

void display() {

    NODE temp=root;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;

}

void rev(int k,int n) {
    int i,j;
    NODE curr = root;
    NODE temp;
    NODE nxt;
    NODE prev = NULL;
    NODE next = NULL;
    for(i=1;i<=n;i+=k) {
        
        if(i==1) {
            temp = curr;
        }
        else {
            nxt = curr;
        }

        j = 1;
        while(j<=k) {    
            if(curr==NULL) {
                break;
            }
            next = curr->right;
            curr->right = prev;
            prev = curr;
            curr = next;
            j++;
        }
         
        if(i==1) {
            root = prev;
        }
        else {
            temp->right = prev;
            temp = nxt;
            nxt->right = NULL;
        }
    }
}


int main() {

    int n,val,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>val;

        insertAfter(val);
    }

    rev(k,n);
    display();



}