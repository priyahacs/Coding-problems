#include <iostream>
#include <string.h>

using namespace std;

/*1.2 Implement a function void reverse(char* str) in C or C++ which reverses a nullterminated
string.*/



void reverse(char * str)
{
    char * start = str;
    char *end = str;
    
    //char * end = str+(strlen(str)-1);
    
    while (*end != '\0')
    {
        end++;
    }
    
    end--;
    
    while(start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start ++;
        end --;
    }
    cout<<str<<endl;
}


/*reverse string using recursion*/

string reverse_recur(string input)
{
    if(input.length() == 0)
    {
        return "";
    }
    else
    {
        
    return reverse_recur(input.substr(1,input.length()))+input[0];
    
    }
        
}

int main()
{
    char str[] = "hello";
    
    char input[] = "welcome";
    //cout<< strlen(str);

    
    reverse(str);
    
    string result = reverse_recur(input);
    cout<<result;
    return 0;
}