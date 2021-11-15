#include <iostream>
using namespace std;

/*
Binary search tree is a binary tree with a special property. 
For every element in the search tree, element at left always smaller while element at right is always bigger.
*/

// Binary tree node
struct node
{
    int data;
    node *left, *right, *p;

    node() { data = 0, left = right = p=  NULL;}

    node(int val){data = val, left=right=p=NULL;}

};


// Traversing a binary search tree
void inorder(node *); //  left-child => self => right-child
void postorder(node *); // left-child => right-child => self
void preorder(node *); // self => left-child  => right-child

// Traversing a binary search tree using inorder traversal will give the ouput in sorted order.

//  Quering the binary search tree
bool searchTree(node *head, int val);
int minimumTree(node *head);
int maximumTree(node *head);
node* successorTree(node *head);
node* predecessorTree(node *head);

int main()
{
    return 0;
}

node* successorTree(node *head)
{
    return head->right;
}

bool searchTree(node *head, int val)
{
    if (!head) return false;

    if (head->data > val) return searchTree(head->left, val);
    if (head->data < val) return searchTree(head->right, val);
    else return head->data;
}

int minimumTree(node *head)
{
    while (head->left)
    {
        head = head->left;
    }

    return head->data;
}

int maximumTree(node *head)
{
    while (head->right)
    {
        head = head->right;
    }

    return head->data;
}

void inorder(node *head)
{
    if (!head) return;

    inorder(head->left);
    cout << head->data << " ";
    inorder(head->right);
}

void postorder(node *head)
{
    if (!head) return;

    postorder(head->left);
    postorder(head->right);
    cout << head->data << " ";
}

void preorder(node *head)
{
    if (!head) return;

    cout << head->data << " ";
    preorder(head->left);
    preorder(head->right);
}