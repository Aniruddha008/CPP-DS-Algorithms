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
        left=right = NULL;
    }
};

int maxlevel = 0;
//At every level print the left most node
void PrintLeftViewIterative(Node* node)
{
    if (node == NULL) return;
    
    queue<Node*> q;
    q.push(node);
   

    while(q.empty() == false)
    {
        int count = q.size();
        for (size_t i{0}; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == 0)
            {
                cout << curr->data << " "; 
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                q.push(curr->right);
            }

        }
    }
    
}

//int maxlevel = 0;
void PrintLeftViewRecursive(Node* node, int level)
{
    if (node == NULL) return;
    cout << "level = " << level << " maxlevel = " << maxlevel << endl;
    if (maxlevel < level)
    {
        cout << node->data << endl;
        maxlevel = level;
    }

    PrintLeftViewRecursive(node->left, level + 1);
    PrintLeftViewRecursive(node->right, level + 1);

}


int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    

    PrintLeftViewIterative(root);
    //PrintLeftViewRecursive(root, 1);
    return 0;
}
