#include<iostream>
#include<list>
#include<vector>
using namespace std;

/*4.4 Given a binary tree, design an algorithm which creates a linked list of all the
 nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked
 lists). Time -O(n) space - O(n)*/



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

/*
 
 Creating the folowing tree:
 
 15
 /    \
 12      20
 /  \    /  \
 10  13  16  25
 
 */

vector < list<Node *> > createLink(Node * head)
{
    vector< list<Node *> > result;
    list<Node *> current;
    
    if(head != NULL)
    {
        current.push_back(head);
    }
    
    while(current.size() > 0)
    {
        result.push_back(current);
        
        list< Node *> parent = current;
        current.clear();
        
        list<Node *>::iterator i;
        
        for(i = parent.begin();i != parent.end(); i++)
        {
            Node * temp = *i;
            if(temp->left != NULL)
            {
                current.push_back(temp->left);
            }
            if(temp->right != NULL)
            {
                current.push_back(temp->right);
            }
        }
    }
    
    return result;
    
}

void printList(list<Node*> ans)
{
    list<Node*>::iterator it;
    for(it=ans.begin();it!=ans.end();it++)
    {
        cout<<(*it)->val<<" ";
    }
}


void print(vector< list<Node *> > result )
{
   
    vector< list<Node *> > ::iterator it;
    for(it=result.begin();it!=result.end();it++)
    {
        list<Node *> temp = *it;
        printList(temp);
        cout<<endl;
    }
}

void print_level(Node * head)
{
    list<Node *> l1;
    
    if(head != NULL)
    {
        l1.push_back(head);
    }
    
    while(l1.size() > 0)
    {
        list<Node *>:: iterator it;
        list <Node * > l2 = l1;
        l1.clear();
        for(it = l2.begin(); it!= l2.end(); it++)
        {
            Node * temp = *it;
            cout<<temp->val<<" ";
            if(temp->left != NULL)
            {
                l1.push_back(temp->left);
            }
            if(temp->right != NULL)
            {
                l1.push_back(temp->right);
            }
        }
        cout<<endl;
    }
    return;
}


int main()
{
    Node *head = new Node(15);
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
    
    
    vector < list<Node *> > result = createLink(head);
    
    print(result);
    
    //bonus print line by line
    
    print_level(head);
    
    //list_ans.push_back(head);
    
    //Node * temp = list_ans[0];
    
    return 0;
}
