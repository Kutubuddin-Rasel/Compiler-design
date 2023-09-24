#include<iostream>
using namespace std;

bool check(char c)
{
    return(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '=' || c == '<' || c == '>');
}

int main()
{
    string a;
    cout<<"Enter output: ";
    cin>>a;
    for(int i=0;i<a.length();i++)
    {
        if(check(a[i]))
        {
            cout<<"operator is: "<<a[i]<<endl;
        }
    }
}