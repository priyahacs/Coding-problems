#include<iostream>
#include<list>
#include<vector>
using namespace std;


/*4.9 You are given a binary tree in which each node contains a value. Design an algorithm
 to print all paths which sum to a given value. The path does not need to start
 or end at the root or a leaf Time- O(n logn) space- O(log n) */

struct Node
{
    int val;
    Node * left, *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void printList(vector<int> ans, int i)
{
    for(int j = i; j < ans.size();j++)
    {
        cout<<ans[j]<<" ";
    }
    return;
}

void printPath(Node * root, vector<int> &path,int sum)
{
    if(root == NULL)
    {
        return;
    }
    path.push_back(root->val);
    printPath(root->left, path, sum);
    printPath(root->right, path, sum);
    
    int temp = 0;
    for(int i = path.size()-1; i>= 0;i--)
    {
        temp += path[i];
        if(temp == sum)
        {
            printList(path,i);
            cout<< endl;
        }
    }
    path.pop_back();
    return;
}

/*
 
 Creating the folowing tree:
 
 1
 /    \
 2      6
 /  \    /  \
 6  13  3  9
 
 */

int main()
{
    Node *head = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(6);
    Node *node3 = new Node(6);
    Node *node4 = new Node(13);
    Node *node5 = new Node(3);
    Node *node6 = new Node(9);
    
    
    head->left = node1;
    head->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    node2->left = node5;
    node2->right = node6;
    
    vector <int> path;
    printPath(head, path, 9);
    
    return 0;
}
