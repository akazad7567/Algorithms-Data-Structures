#include<bits/stdc++.h>
using namespace std;
#define M 500
int dp[M];

void ini()
{
    for(int i=0;i<M;i++)
    {
       dp[i]=-1;
    }
}

bool f(int ar[],int i,int n,int w)
{
    if(w==0) return 1;
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];

    bool r1=f(ar,i+1,n,w-ar[i]);
    bool r2=f(ar,i+1,n,w);
    dp[i]=r1 or r2;
    return dp[i];
}
int main()
{
    ini();
    int n,w;
    cin>>n>>w;
    int ar[n+10];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    cout<<f(ar,0,n,w)<<endl;
}

