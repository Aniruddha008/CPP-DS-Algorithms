#include<iostream>
using namespace std;

    /*
    1. we first created a root node with value 10.
    we are allocating memory dynamically hence we used new keyword.

    2. then we create the left child, and connect it to the root.
    lly for right child.

    3. we create another left child of the left child.
    
    */


struct Node
{
    int data;
    Node *left, *right ;

    Node(int k)
    {
        data = k;
        left = right = NULL;
    }

};

void InorderTraversal(Node* node)
{
    if (node == NULL) return;

    InorderTraversal(node->left);
    cout << node->data << endl;
    InorderTraversal(node->right);
}

void PreOrderTraversal(Node* node)
{
    if(node == NULL) return;

    cout << node->data << endl;
    PreOrderTraversal(node->left);
    PreOrderTraversal(node->right);
}

void PostOrderTraversal(Node* node)
{
    if (node == NULL) return;

    PostOrderTraversal(node->left);
    PostOrderTraversal(node->right);
    cout << node->data << endl;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << "Inorder Traversal" << endl;
    InorderTraversal(root);

    cout << endl;
    cout << "Preorder Traversal" << endl;
    PreOrderTraversal(root);

    cout << endl;
    cout << "Postorder Traversal" << endl;
    PostOrderTraversal(root);


}