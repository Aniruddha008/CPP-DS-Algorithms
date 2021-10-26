#include<iostream>
using namespace std; 

struct Node 
{
    int data;
    Node *left, *right;

    Node (int k)
    {
        data = k;
        left = right = NULL;
    }

};

int BinaryTreeHeight(Node* node)
{
    if (node == NULL) return 0;

    else 
    {
        return max(BinaryTreeHeight(node->left), BinaryTreeHeight(node->right)) + 1;
    }
    
}


int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->right->left = new Node(50);
    root->right->right = new Node(60);
    root->left->left = new Node(70);


    /*
                10

            20      30

        40        50    60

               70  


    height = 3

    */

    cout << "height = " << BinaryTreeHeight(root);
    
    return 0;
}