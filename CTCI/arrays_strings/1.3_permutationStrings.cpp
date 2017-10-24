#include<iostream>
using namespace std;

/*Given two strings, write a method to decide if one is a permutation of the other.*/



/*Using extra space
 space - O(1)
 time - O(n)*/
bool checkAnagrams (string A, string B)
{
    int count[256];
    
 
    
    if( A.length() == 0 || B.length() == 0)
    {
        return false;
    }
    
    if(A.length() != B.length())
    {
        return false;
    }
    
    
    for(int i=0;i<256;i++)
    {
        count [i] = 0;
    }
    
    for(int i=0;i<A.length();i++)
    {
        count[A[i] - 'a']++;
        count[B[i] - 'a']--;
    }
    
    for(int i=0;i<256;i++)
    {
        if(count[i] > 0)
        {
            return false;
        }
    }
    
    return true;
}

/*Not Using extra space
 space - O(1)
 time - O(nlogn)*/

bool checkAnagrams_nospace (string A, string B)
{
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
 
    return (A == B);
}

int main()
{
    string A = "angel";
    string B = "glean";
    
    bool result = checkAnagrams(A,B);
    
    if(result == false)
    {
        cout <<"The srings are not anagrams"<<endl;
    }
    else
    {
        
        cout <<"The string are anagrams"<<endl;
    }
    
    
    bool result1 = checkAnagrams_nospace(A,B);
    
    if(result1 == false)
    {
        cout <<"The srings are not anagrams"<<endl;
    }
    else
    {
        
        cout <<"The string are anagrams"<<endl;
    }

    
    return 0;
}