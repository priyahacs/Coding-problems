#include<iostream>

using namespace std;


struct Node
{
    int value;
    Node *next;
    
    Node(int val)
    {
        this->value = val;
        this->next = NULL;
    }
};


class solution
{
private:
    Node * head;
    int length;
    
public:
    
    solution()
    {
        this->head = NULL;
    }
    
    void print()
    {
        Node *cur = head;
        
        while(cur != NULL)
        {
            cout<<cur->value<<",";
            cur = cur->next;
        }
        return;
        
    }
    
    void insertAtEnd(int val)
    {
        Node *cur = head;
        if(head == NULL)
        {
            head = new Node(val);
            length = 1;
        }
        else
        {
          
            Node *temp = new Node(val);
            
            while(cur->next != NULL)
            {
                cur =cur->next;
            }
            
            cur->next = temp;
            length++;
            
        }
        return;
    }
    
    int findLength()
    {
        return this->length;
    }
    
    
    Node * getHead()
    {
        return this->head;
    }
    
    
    int returnKElement(Node * head,int k);
    void removeDuplicates(Node *head);
    
    
    /* 2.3 Implement an algorithm to delete a node in the middle of a singly linked list,
     given only access to that node.
     EXAMPLE
     Input: the node c from the linked list a->b->c->d->e
     Result: nothing is returned, but the new linked list looks like a- >b- >d->e */

    
    void deleteMiddleWrapper()
    {
        int val = 1;
        
        Node *cur1 = this->head;
        
        while(cur1 != NULL)
        {
            if(cur1->value == val)
            {
                break;
            }
            cur1 = cur1->next;
        }
        
        deleteMiddle(cur1);
        
        return ;
    }
    
    
    void deleteMiddle(Node * ptr)
    {
        Node *runner = ptr;
        Node *prev;
        
        while(runner->next != NULL)
        {
            prev = runner;
            runner->value = runner->next->value;
            runner = runner->next;
            
        }
        prev->next = NULL;
        return;
        
    }
    
    /*End of 2.3*/
    
};
    
/*2.2 Implement an algorithm to find the kth to last element of a singly linked list.*/


int solution::returnKElement(Node * head, int k)
{
    if(head == NULL)
    {
        return 0;
    }
    int i = returnKElement(head->next,k) +1;
    
    if(i== k)
    {
        cout<<"The element is "<< head->value <<endl;
    }
    return i;
}

/*end of 2.2*/



/*2.1 Write code to remove duplicates from an unsorted linked list.
 FOLLOW UP
 How would you solve this problem if a temporary buffer is not allowed?*/


void solution::removeDuplicates(Node *head)
{
    Node *cur = head;
    
    while(cur != NULL)
    {
        Node *ptr = cur;
        
        while(ptr->next != NULL)
        {
            if(cur->value == ptr->next->value)
            {
                ptr->next = ptr->next->next;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        
        cur = cur->next;
    }
    
    return;
    
}



int main()
{
    solution link1;
    
    int arr[] = {4,5,4,2,10,1,6,5,10};
    
    int len = sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0;i<len;i++)
    {
        link1.insertAtEnd(arr[i]);
    }
    
    link1.print();
    
    cout<<endl;
    
    
    link1.deleteMiddleWrapper();
    
    
    link1.print();
    cout<<endl;
    
    int k= 2;
    int i= 0;
    int val = link1.returnKElement(link1.getHead(),k);
    
    link1.removeDuplicates(link1.getHead());
      cout<<endl;
    link1.print();
    
    return 0;
}