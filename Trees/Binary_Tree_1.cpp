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


int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

}