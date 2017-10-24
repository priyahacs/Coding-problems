#include <iostream>
#include <map>
using namespace std;



/*Implement an algorithm to determine if a string has all unique characters. What
if you cannot use additional data structures?*/


/*Method 1 using extra space
 space - O(n)
 time - O(n)*/
bool check_unique_map(string str)
{
    map <int,int> m1;
    
    int len = str.length();
    
    for(int i=0;i<len;i++)
    {
        if(m1.find(str[i]) == m1.end())
        {
            m1[str[i]] = 1;
        }
        else
        {
            return false;
        }
    }
    return true;
}


/*Method 2 without using extra space
 space - O(1)
 time - O(nlogn)+O(n)*/

bool check_unique_inplace(string str)
{
    sort(str.begin(),str.end());
    int i =0;
    
    for(int j=1;j<str.length();j++)
    {
        if(str[i] != str[j])
        {
            i++;
        }
        else
        {
            return false;
        }
    }
    
    return true;
    
}

int main()
{
    string str = "hello welcome";
    
    bool result = check_unique_map(str);
    
    if(result == false)
    {
        cout <<"The string does not contain unique letters"<<endl;
    }
    else
    {
     
        cout <<"The string contain unique letters"<<endl;
    }
    
    bool result1 = check_unique_inplace(str);
    
    if(result1 == false)
    {
        cout <<"The string does not contain unique letters"<<endl;
    }
    else
    {
        
        cout <<"The string contain unique letters"<<endl;
    }

    
    return 0;
    
}
