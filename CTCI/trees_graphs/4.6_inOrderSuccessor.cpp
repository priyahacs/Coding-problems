#include <iostream>
using namespace std;
/*4.6 Write an algorithm to find the'next'node (i.e., in-order successor) of a given node
 in a binary search tree. You may assume that each node has a link to its parent. 
 Time- O(h) height of the tree*/
struct Node
{
    int data;
    Node * left, *right, * parent;
    
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};


Node * findSuccessor(Node * head)
{
    if(head->right != NULL)
    {
        Node * temp = head->right;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    else
    {
        Node * ans  = head->parent;
        while(ans != NULL && ans->right == head)
        {
            head = ans;
            ans = ans->parent;
        }
        return ans;
    }
    
}



/*
 
 Creating the folowing tree:
 
 15
 /    \
 12      20
 /  \    /  \
 10  13  16  25
 
 */

int main()
{
    Node *head = new Node(15);
    //solution tp;
    
   Node *node1 = new Node(12);
   Node *node2 = new Node(20);
    Node *node3 = new Node(10);
    Node *node4 = new Node(13);
    Node *node5 = new Node(16);
    Node *node6 = new Node(25);
    
    
    head->left = node1;
    head->right = node2;
    
    node1->left = node3;
    node1->right = node4;
    
    node2->left = node5;
    node2->right = node6;
    
    
    node1->parent = head;
    node2->parent = head;
    node3->parent = node1;
    node4->parent = node1;
    node5->parent = node2;
    node6->parent = node2;
    
    //node4->right = node5;
    //node5->right = node6;
    Node * succ = findSuccessor(node4);
    
    if(succ != NULL)
    {
        cout<<succ->data;
    }
    else
    {
        cout<<" It has no successor";
    }
    
    
    return 0;
}
