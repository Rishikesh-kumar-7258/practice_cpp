#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int v)
    {
        data = v;
        left = NULL;
        right = NULL;
    }
};

struct Tree
{
    int data;
    Node *leftchild, *rightsibling;

    Tree(int v) {data = v; leftchild = NULL; rightsibling = NULL;}
};

void binaryTreeIteration(Node *head); // binary Tree interation
void TreeIteration(Node *head); // Tree iteration

int main()
{
    return 0;
}

void TreeIteration(Tree *head)
{
    if (!head) return;

    cout << head->data << " ";
    TreeIteration(head->rightsibling);
    TreeIteration(head->leftchild);

    return;
}

void binaryTreeIteration(Node *head)
{
    if (!head) return;

    cout << head->data << " ";
    binaryTreeIteration(head->left);
    binaryTreeIteration(head->right);

    return;
}