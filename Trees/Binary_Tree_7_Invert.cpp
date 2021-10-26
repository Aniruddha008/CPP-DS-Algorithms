#include<iostream>
#include<queue>
using namespace std;

struct Node 
{
    int data;
    Node *left, *right;

    Node(int k)
    {
        data = k;
        left = right = NULL;
    }
};

void Invert(Node* node)
{
/*    
    cout << node->data << " ";
    cout << node->left->data << " ";
    cout << node->right->data << " ";
*/

    if (node == NULL) return;

    Invert(node->left);
    Invert(node->right);

    Node *temp;
    temp = node->left;
    node->left = node->right;
    node->right = temp;
    
    
/*
    cout << endl; 

    cout << node->data << " ";
    cout << node->left->data << " ";
    cout << node->right->data << " " ;
*/
}

void LevelOrderTraversal4(Node *node)
{
    if (node == NULL) return;

    queue <Node*> q;
    q.push(node);

    while (q.empty() == false)
    {
        int count = q.size();

        for (size_t i{0}; i < count ; i++)
        {
            Node *curr = q.front();
            q.pop();

            cout << curr->data << " ";
            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
            
        }
        cout << endl;
    }
}

int main()
{
    Node *root = NULL;

    root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);

    LevelOrderTraversal4(root);
    cout << endl;
    Invert(root);
    LevelOrderTraversal4(root);

    return 0;
}