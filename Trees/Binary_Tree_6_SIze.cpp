#include<iostream>
#include<queue>
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


void BTSize(Node *node)
{
    if (node == NULL) return;
    
    int binary_tree_size = 0; 
    queue <Node*> q;
    q.push(node);

    while (q.empty() == false)
    {
        int count = q.size();
        binary_tree_size += count;
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

    cout << endl;
    cout << " Binary tree size = " << binary_tree_size << endl;

}

void BTMax(Node *node)
{
    if (node == NULL) return;
    
    int binary_tree_max = node->data; 
    queue <Node*> q;
    q.push(node);

    while (q.empty() == false)
    {
        int count = q.size();
        
        for (size_t i{0}; i < count ; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->data > binary_tree_max)
            {
                binary_tree_max = curr->data;
            }

            cout << curr->data << " ";
            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
            
        }
        cout << endl;
    }

    cout << endl;
    cout << " Maximum Binary tree node = " << binary_tree_max << endl;
}

int BTSize2(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else 
    {
        return 1 + BTSize2(node->left) + BTSize2(node->right);
    }
    
}

int BTMax2(Node* node)
{
    if (node == NULL)
    {
        return INT_MIN;
    }
    else  
    {
        return  max(
            node->data
            ,
            max(BTMax2(node->left), BTMax2(node->right))
        );
    }
    
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(140);
    root->right->left = new Node(50);
    root->right->right = new Node(60);
 


    /*
                10
               /   \
            20      30
           /   \      \
        40      50    60

              

    k = 2
    o/p = 40 50 70

    */
    
    cout << "Size = " << BTSize2(root);
    BTMax2(root);
    return 0;
}