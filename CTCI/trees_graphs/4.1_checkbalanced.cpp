
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*4.1 Implement a function to check if a binary tree is balanced. For the purposes of this
question, a balanced tree is defined to be a tree such that the heights of the two
subtrees of any node never differ by more than one.*/

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


class solution
{
public:
    int getHeight(BinaryTreeNode * head);
    bool checkBalanced(BinaryTreeNode * head);
};


int solution::getHeight(BinaryTreeNode * head)
{
    if(head != NULL )
    {
        return (max(getHeight(head->left),getHeight(head->right)))+ 1;
    }
    else
    {
        return 0;
    }
}

bool solution::checkBalanced(BinaryTreeNode * head)
{
    if(head == NULL)
    {
        return true;
    }
    
    int h1 = getHeight(head->left);
    int h2 = getHeight(head->right);
    
    if (abs(h1-h2) >1)
    {
        return false;
    }
    else
    {
        bool b1 = checkBalanced(head->left);
        bool b2 = checkBalanced(head->right);
        return b1 && b2;
    }
}

/*
 
 Creating the folowing tree:
 
 10
 /  \
 11     12
 /  \    /  \
 13  14   15  16
 
 */



int main()
{
    BinaryTreeNode *head = new BinaryTreeNode(10);
    solution tp;
    
    BinaryTreeNode *node1 = new BinaryTreeNode(11);
    BinaryTreeNode *node2 = new BinaryTreeNode(12);
    BinaryTreeNode *node3 = new BinaryTreeNode(13);
    BinaryTreeNode *node4 = new BinaryTreeNode(14);
    BinaryTreeNode *node5 = new BinaryTreeNode(15);
    BinaryTreeNode *node6 = new BinaryTreeNode(16);
    
    
    head->left = node1;
    head->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    node2->left = node5;
    node2->right = node6;
    
    //node4->right = node5;
    //node5->right = node6;
    cout<<tp.checkBalanced(head);
    
    
    return 0;
}