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

int HeightBT(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else 
    {
        return max(HeightBT(node->left), HeightBT(node->right)) + 1;
    }
}


void PrintNodesAtDistance(Node *node, int k)
{
    if (node == NULL) return;

    if (k == 0)
    {
        cout << node->data << endl;
    }
    else 
    {
        PrintNodesAtDistance(node->left, k - 1);
        PrintNodesAtDistance(node->right, k - 1);
    }
}


void LevelOrderTraversal(Node *node)
{
    if (node == NULL) return;

    /*
    1. first Find the height, i.e num of levels
    2. start printing nodes from distance k = 0 to k = height
    
    */

   int num_levels = HeightBT(node);
   cout << "No of levels = " << num_levels <<endl;

   for (size_t i{0}; i < num_levels; i++)
   {
       PrintNodesAtDistance(node, i);
       cout << endl;
   }

}


void LevelOrderTraversal2(Node *node)
{
    if (node == NULL) return;

    queue<Node*> q ;
    q.push(node);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << endl;
        if (curr->left != NULL) q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);
         
    }
    
}

void LevelOrderTraversal3(Node *node)
{

    if (node == NULL) return;

    queue <Node*> q;
    q.push(node);
    q.push(NULL);

    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop(); 
        if (curr == NULL)
        {
            cout << endl;
            q.push(NULL); // end of level marker
            continue;
        }
        cout << curr->data << " ";
        if (curr->left != NULL) q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);
                
    } 

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
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
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
    
    //LevelOrderTraversal(root);
    //LevelOrderTraversal2(root);   
    //LevelOrderTraversal3(root);
    LevelOrderTraversal4(root);
    return 0;
}