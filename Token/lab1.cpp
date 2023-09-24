#include<iostream>
using namespace std;

bool check(string a)
{
    int b = a.length();
    for(int i=0;i<b;i++)
    {
        if(isdigit(a[i])==false)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string a;
    cout<<"Enter output: ";
    cin>>a;
    if(check(a))
    {
        cout<<"Numeric";
    }
    else
    {
        cout<<"Not numeric";
    }
}