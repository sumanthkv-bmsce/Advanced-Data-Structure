#include<iostream>
using namespace std;
struct BTreeNode
{
    int *data;
    BTreeNode **child_ptr;
    bool leaf;
    int n;
}*root = NULL, *np = NULL, *x = NULL;
int m;
BTreeNode * init()
{
    int i;
    np = new BTreeNode;
    np->data = new int[m-1];
    np->child_ptr = new BTreeNode *[m];
    np->leaf = true;
    np->n = 0;
    for (i = 0; i < m; i++)
    {
        np->child_ptr[i] = NULL;
    }
    return np;
}
void traverse(BTreeNode *p)
{
    cout<<endl;
    int i;
    for (i = 0; i < p->n; i++)
    {
        if (p->leaf == false)
        {
            traverse(p->child_ptr[i]);
        }
        cout << " " << p->data[i];
    } 
    if (p->leaf == false)
    {
        traverse(p->child_ptr[i]);
    }
    cout<<endl;
}
void sort(int *p, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (p[i] > p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
int split_child(BTreeNode *x, int i)
{
    int j, mid,org;
    BTreeNode *np1, *np3, *y;
    np3 = init();
    np3->leaf = true;
    if (i == -1)
    {   
        
        mid = x->data[(m-1)/2];
        
        x->data[(m-1)/2] = 0;
        x->n--;
        np1 = init();
        np1->leaf = false;
        x->leaf = true;
        for (j = ((m-1)/2)+1; j < (m-1); j++)
        {
            np3->data[j - ((m-1)/2)-1] = x->data[j];
            np3->child_ptr[j - ((m-1)/2)-1] = x->child_ptr[j];
            np3->n++;
            x->data[j] = 0;
            x->n--;
        }
        for (j = 0; j < m; j++)
        {
            x->child_ptr[j] = NULL;
        }
        np1->data[0] = mid;
        np1->child_ptr[np1->n] = x;
        np1->child_ptr[np1->n + 1] = np3;
        np1->n++;
        root = np1;
    }
    else
    {
        y = x->child_ptr[i];
        mid = y->data[((m-1)/2)];
        y->data[(m-1)/2] = 0;
        y->n--;
        for (j = ((m-1)/2)+1; j < m-1; j++)
        {
            np3->data[j - ((m-1)/2)-1] = y->data[j];
            np3->n++;
            y->data[j] = 0;
            y->n--;
        }
        x->child_ptr[i + 1] = y;
        x->child_ptr[i + 1] = np3; 
    }
    return mid;
}
void insert(int a)
{
    int i, temp;
    x = root;
    if (x == NULL)
    {
        root = init();
        x = root;
    }
    else
    {
        if (x->leaf == true && x->n == m-1)
        {
            temp = split_child(x, -1);
            x = root;
            for (i = 0; i < (x->n); i++)
            {
                if ((a > x->data[i]) && (a < x->data[i + 1]))
                {
                    i++;
                    break;
                }
                else if (a < x->data[0])
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            x = x->child_ptr[i];
        }
        else
        {
            while (x->leaf == false)
            {
            for (i = 0; i < (x->n); i++)
            {
                if ((a > x->data[i]) && (a < x->data[i + 1]))
                {
                    i++;
                    break;
                }
                else if (a < x->data[0])
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
                if ((x->child_ptr[i])->n == m-1)
                {
                    temp = split_child(x, i);
                    x->data[x->n] = temp;
                    x->n++;
                    continue;
                }
                else
                {
                    x = x->child_ptr[i];
                }
            }
        }
    }
    x->data[x->n] = a;
    sort(x->data, x->n);
    x->n++;
}
int main()
{
    int i, n, t;
    cout<<"enter the no of elements to be inserted\n";
    cin>>n;
    cout<<"Enter the order or degree\n";
    cin>>m;
    cout<<"Enter the elements"<<endl;
    for(i = 0; i < n; i++)
    {
          cin>>t;
          insert(t);
    }
    cout<<"The elements are "<<endl;
    traverse(root);
}