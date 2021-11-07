//'mod' could be prime or non prime
//time complexity log(n^2)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll const mxn=10000;
ll nCr[mxn][mxn];
ll const mod=1e9;

void cal()
{
    nCr[0][0]=1;
    nCr[0][1]=0;
    for(ll i=1;i<mxn;i++)
    {
        nCr[i][0]=1;
        for(ll j=1;j<=i;j++)
        {
           nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%mod;
        }
    }
}
int main()
{
    cal();
    ll n,r;
    cin>>n>>r;
    cout<<nCr[n][r]<<endl;
}
