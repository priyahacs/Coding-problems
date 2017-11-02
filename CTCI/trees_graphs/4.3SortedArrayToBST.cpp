#include <iostream>
using namespace std;


/*4.3 Given a sorted (increasing order) array with unique integer elements, write an
 algorithm to create a binary search tree with minimal height.
 
 Time - O(n)
 space - O(n)//since returning a new tree
 */
struct Node
{
    int data;
    Node * left, *right;
    
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


Node * convertToBST(int arr[], int start,int end)
{
    if(start <= end)
    {
        int mid = (start+end)/2;
        
        Node * root = new Node(arr[mid]);
        //cout<<root->data<<mid<<endl;

        
        root->left = convertToBST(arr, start, mid-1);
        root->right = convertToBST(arr, mid+1, end);
        
        //cout<<root->data<<endl;
        return root;
    }
    else
    {
        return NULL;
    }
}

void preOrder(Node * root)
{
    if(root == NULL)
    {
        return;
    }
    
    cout<<root->data;
    preOrder(root->left);
    preOrder(root->right);
    
    return;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    Node * root = convertToBST(arr,0,len-1);
    
    preOrder(root);
    
    return 0;
}
