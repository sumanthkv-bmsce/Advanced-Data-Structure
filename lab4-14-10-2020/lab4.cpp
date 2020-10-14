#include<bits/stdc++.h>

using namespace std;

struct avl {
    int data;
    struct avl *l;
    struct avl *r;
};

typedef struct avl* AVL;
AVL r = NULL;

class avl_tree {
    public:
        int height(AVL);
        int difinheight(AVL);
        AVL rr_rot(AVL);
        AVL ll_rot(AVL);
        AVL lr_rot(AVL);
        AVL rl_rot(AVL);
        AVL balance(AVL);
        AVL insert(AVL,int);
        AVL remove(int,AVL);
        AVL remove(AVL,int); 
        void inorder(AVL);
        void preorder(AVL);
};

int avl_tree::height(AVL node) {
    if(node==NULL) return 0;

    int l_h = height(node->l);
    int r_h = height(node->r);

    return max(l_h,r_h) + 1;
}

int avl_tree::difinheight(AVL node) {

    int l_h = height(node->l);
    int r_h = height(node->r);

    int balanceFactor = l_h-r_h;
    return balanceFactor;

}

AVL avl_tree::rr_rot(AVL par) {
    AVL child;

    child = par->r;
    par->r = child->l;
    child->l = par;
    return child;
}

AVL avl_tree::ll_rot(AVL par) {
    AVL child;

    child = par->l;
    par->l = child->r;
    child->r = par;
    return child;
}

AVL avl_tree::lr_rot(AVL par) {
    AVL child;

    child = par->l;
    par->l = rr_rot(child);
    return ll_rot(par);
}

AVL avl_tree::rl_rot(AVL par) {
    AVL child;

    child = par->r;
    par->r = ll_rot(child);
    return rr_rot(par);
}

AVL avl_tree::balance(AVL node) {

    int balFactor = difinheight(node);

    if(balFactor>1) {
        if(difinheight(node->l)>0) {
            node = ll_rot(node);
        }
        else {
            node = lr_rot(node);
        }
    }
    else if(balFactor<-1) {
        if(difinheight(node->r)>0) {
            node = rl_rot(node);
        }
        else {
            node = rr_rot(node);
        }
    }

    return node;

}

AVL avl_tree::insert(AVL node,int val) {

    if(node==NULL) {
        node = (AVL)malloc(sizeof(struct avl*));
        node->data = val;
        node->l = NULL;
        node->r = NULL;
        return node;
    }

    if(val<node->data) {
        node->l = insert(node->l,val);
        node = balance(node);
    }

    if(val>node->data) {
        node->r = insert(node->r,val);
        node = balance(node);
    }

    return node;

}

void avl_tree::inorder(AVL par) {

    if(par!=NULL) {
        inorder(par->l);
        cout<<par->data<<" ";
        inorder(par->r);
    }

}

void avl_tree:: preorder(AVL par) {

    if(par!=NULL) {
        cout<<par->data<<" ";
        preorder(par->l);
        
        preorder(par->r);
    }

}

AVL predecessor(AVL node,int val) {

    AVL temp = node;
    while(temp->l->data!=val && temp->r->data!=val) {
        
        if(temp->data<val) {
            temp = temp->r;
        }
        else {
            temp = temp->l;
        }

    }

    return temp;


}

// AVL avl_tree::remove(int x,AVL node) {

//     AVL temp;
//     if(node==NULL) return NULL;

//     else if(node->data==x) {
//         if(node->l!=NULL && node->r!=NULL) {
//             temp = node->r;

//             while(temp->l!=NULL) {
//                 temp = temp->l;
//             }

//             node->data = temp->data;
//             node->r = remove(node->data,node->r);
//             balance(node);
//             return node;
//         }
//         else {

//             temp=predecessor(r,x);
//             cout<<"Predec "<<temp->data<<endl;
//             if(temp->l && temp->l->data==x) {
//                 // cout<<temp->l->data<<" "<<x<<endl;
//                 temp->l = temp->l->l;

//             }
//             else if(temp->r){
//                 temp->r = temp->r->r;
//                 cout<<temp->data<<" "<<temp->r->data<<endl;
//             }

//             temp = node;
//             delete node;
//             balance(temp);
//             return temp;



//         }
//     }

//     else if(x<node->data) {
//         node->l = remove(x,node->l);
//     }
//     else if(x>node->data) {
//         node->r = remove(x,node->r);
//     }
    


// }

AVL avl_tree:: remove(AVL root, int key)  
{  
       
    if (root == NULL)  
        return root;  
  
    
    if ( key < root->data )  
        root->l = remove(root->l, key);  
  
     
    else if( key > root->data )  
        root->r = remove(root->r, key);  
  
    
    else
    {  
      
        if( (root->l == NULL) || 
            (root->r == NULL) )  
        {  
            AVL temp = root->l ?  
                         root->l :  
                         root->r;  
  
             
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else 
            *root = *temp;
                         
            free(temp);  
        }  
        else
        {  
             
            AVL temp = root->r;
            while(temp->l!=NULL) {
                temp = temp->l;
            }
  
 
            root->data = temp->data;  
    
            root->r = remove(root->r,temp->data);  
        }  
    }  
    
    if (root == NULL)  
    return root;  
  
    root = balance(root);
  
    return root;  
}  


int main() {

    int ele,i,n,ch;
    avl_tree avl;
    while(1) {
        cout<<"Enter 1 to insert the element:"<<endl;
        cout<<"Enter 2 to delete the element:"<<endl;
        cout<<"Enter 3 to display the elements"<<endl;
        cout<<"Press Ctrl+C to exit "<<endl;
        cin>>ch;
        switch(ch) {
            case 1: cout<<"Enter element to be inserted: "<<endl;
                    cin>>ele;
                    r = avl.insert(r,ele);
                    cout<<"Successfully inserted "<<endl;
                    break;
            case 2: cout<<"Enter element to be deleted: "<<endl;
                    cin>>ele;
                    r = avl.remove(r,ele);
                    cout<<"Successfully deleted "<<endl;
                    break;
            case 3: avl.inorder(r);
                    break;
            default: cout<<"Select the correct choice"<<endl;
                    break;
        }
        cout<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<endl;
    }


}
