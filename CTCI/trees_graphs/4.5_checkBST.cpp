#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*4.5 Implement a function to check if a binary tree is a binary search tree.
 time complexity: O(n), space complexity:O(log n)- due to recursive call if not considered its O(1)*/


struct BinaryTreeNode{
    
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    
public:
    BinaryTreeNode(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
    
};



/*
 
 Creating the folowing tree:
 
     15
   /    \
 12      20
 /  \    /  \
10  13  16  25
 
 */
class solution
{
public:
    bool checkIfBST(BinaryTreeNode * head, int min, int max);
};


bool solution::checkIfBST(BinaryTreeNode * head, int min,int max)
{
 
    if(head == NULL)
    {
        return true;
    }
    
    
    if(head->data < min || head->data > max)
        
    {
        return false;
    }
    
    return (checkIfBST(head->left,min,head->data-1) && checkIfBST(head->right, head->data+1, max));
    
}

int main()
{
    BinaryTreeNode *head = new BinaryTreeNode(15);
    solution tp;
    
    BinaryTreeNode *node1 = new BinaryTreeNode(12);
    BinaryTreeNode *node2 = new BinaryTreeNode(20);
    BinaryTreeNode *node3 = new BinaryTreeNode(10);
    BinaryTreeNode *node4 = new BinaryTreeNode(13);
    BinaryTreeNode *node5 = new BinaryTreeNode(16);
    BinaryTreeNode *node6 = new BinaryTreeNode(25);
    
    
    head->left = node1;
    head->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    node2->left = node5;
    node2->right = node6;
    
    //node4->right = node5;
    //node5->right = node6;
    cout<<tp.checkIfBST(head, INT_MIN, INT_MAX);
    
    
    return 0;
}
