#include<bits/stdc++.h>
using namespace std;

int check(int n,int k)
{
    if(n&(1<<(k-1)))
    {return true;}
    else
    {return false;}
}

int main()
{
    int n,x=20,k=1;
    cin>>n;
    int count=0,flag=0;
    while(x-->0)
    {
        int l=k+1;
        if(check(n,k)==1 && check(n,l)==1)
        {
            count++;
            flag=max(flag,count);
        }
        else
        {
            count=0;
        }
        k++;
    }
    cout<<flag+1;
}