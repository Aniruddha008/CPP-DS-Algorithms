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

void PrintNodesATDistance(Node* node, int k)
{
    cout  << "k = " << k << endl;
    if (node == NULL) 
    {
        
        return;
    }
    
    if (k == 0) 
    {
        cout << node->data << " " << endl;
    }
    else 
    {   
        PrintNodesATDistance(node->left, k - 1);
        PrintNodesATDistance(node->right, k - 1);
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
 


    /*
                10

            20      30

        40      50    60

              

    k = 2
    o/p = 40 50 70

    */
    int k = 2;
    PrintNodesATDistance(root, k);
    
    return 0;
}