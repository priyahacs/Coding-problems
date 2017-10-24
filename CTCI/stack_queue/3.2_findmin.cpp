#include<iostream>

using namespace std;

/*How would you design a stack which, in addition to push and pop, also has a
function min which returns the minimum element? Push, pop and min should all
operate in 0(1) time.*/

/*Have used extra variable to keep track of min at each node
 It can also be done using a secondary stack keeping track of min value at top*/

struct Node{
    
    int data;
    int min;
    Node * next;
    
    Node(int data, int min)
    {
        this->data = data;
        this->min = min;
        this->next = NULL;
    }
};

class stack
{
private:
    Node * top;
    int size;

public:
   
    void push(int data);
    void pop();
    int findmin();
    int peek();
};

void stack::push(int data)
{
    Node * temp;
    if(top == NULL)
    {
        temp = new Node(data,data);
        
    }
    else
    {
        int mins = min(data, findmin());
        temp = new Node(data,mins);
        
    }
    temp->next = top;
    top = temp;
    size++;
    return;
    
}

void stack::pop()
{
    if(top == NULL)
    {
        return;
    }
    else
    {
        top = top->next;
        size--;
    }
    return;
}

int stack::peek()
{
    if(top == NULL)
    {
        return INT_MAX;
    }
    else
    {
        return top->data;
    }
}

int stack::findmin()
{
    if(top == NULL)
    {
        return INT_MAX;
    }
    else
    {
        return top->min;
    }
}

int main()
{
    stack s1;
    
    s1.push(2);
    s1.push(5);
    s1.push(1);
    
    int result = s1.peek();

    cout<<result;
    cout<<s1.findmin();
    
    s1.pop();
    cout<<s1.findmin();
    
    s1.push(0);
    cout<<s1.findmin();
    
    return 0;
}