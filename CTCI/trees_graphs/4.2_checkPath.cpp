#include <iostream>
#include <list>
#include <queue>
using namespace std;

/*4.2 Find if there is a path between two vertices in a directed graph
 Time - O(nlogn), space- O(n)*/



class graph{
    
public:
    int V;
    list<int> *adj;
public:
    graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    
    void addEdge(int start, int end);
    bool checkPath(int start,int end);
    
};




void graph::addEdge(int start, int end)
{
    adj[start].push_back(end);
}


bool graph::checkPath(int start, int end)
{
    if (start == end)
        return true;
    
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    queue<int> q1;
    
    q1.push(start);
    list<int>::iterator i;
    
    while(!q1.empty())
    {
        int start = q1.front();
        q1.pop();
        
        for(i = adj[start].begin(); i!= adj[start].end(); i++)
        {
            if (*i == end)
            {
                return true;

            }
            else
            {
                if(!visited[*i])
                {
                    visited[*i] = true;
                    q1.push(*i);
                }
            }
        }
        
    }
    return false;
}



/*
 
 Creating the folowing tree:
 
     0
 /        \
 1         2
 /  \       /  \
 3  4 ->  5    6
 
 */



int main()
{
    graph g1(7);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(1,3);
    g1.addEdge(1,4);
    g1.addEdge(4,5);
    g1.addEdge(2,5);
    g1.addEdge(2,6);
    
    cout<<g1.checkPath(2,4);
    
    
    return 0;
}