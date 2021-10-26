#include<iostream>
#include<stack>
using namespace std; 

struct Node 
{
    int data;
    Node* left, *right;

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
    cout << node->data << " ";
    InorderTraversal(node->right);
}

void InorderTraversalIterative(Node* node)
{
    
    stack <Node*> s;
    Node *curr = node;

    while (curr != NULL || s.empty() == false)
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;

    }
    
}

void PreOrderTraversal(Node* node)
{
    if(node == NULL) return;

    cout << node->data << " ";
    PreOrderTraversal(node->left);
    PreOrderTraversal(node->right);
}


void PreOrderTraversalIterative(Node* node)
{
    if (node == NULL) return;
    
    stack<Node*> s;
    s.push(node);

    while(s.empty() != true)
    {
        Node *curr = s.top();
        cout << curr->data << " ";
        s.pop();
        
        if (curr->right != NULL) s.push(curr->right);

        if (curr->left != NULL) s.push(curr->left);
    }

}



int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
/*
    cout << "Recursive Inorder Traversal:" << endl;
    InorderTraversal(root);
    cout << endl;
    cout << "Iterative Inorder Traversal:" << endl;
    InorderTraversalIterative(root);
*/
    cout << "Recursive Preorder Traversal:" << endl;
    PreOrderTraversal(root);
    cout << endl;
    cout << "Iterative Preorder Traversal:" << endl;
    PreOrderTraversalIterative(root);

    return 0;
}





