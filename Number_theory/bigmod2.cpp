#include<bits/stdc++.h>
using namespace std;

int bigmod(int a,int b,int m)
{   //cout<<"k"<<endl;
    if(b==0) return 1%m;
   // cout<<"next="<<b<<endl;
    int x=bigmod(a,b/2,m);
    //cout<<x<<ends<<b<<endl;
    x=(x*x)%m;
    if(b%2==1) x=(x*a)%m;
    return x;
}

int main()
{
    int a,b,m;
    cin>>a>>b>>m;
    cout<<bigmod(a,b,m);
    getchar();
}
