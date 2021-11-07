#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll nCr(ll n,ll r)
{
    ll res=1;
    for(ll i=1;i<=r;i++)
    {
        res=res*(n-i+1);
        res/=i;
    }
    return res;
}
int main()
{
    ll n,r;
    cin>>n>>r;

    cout<<nCr(n,r)<<endl;
}
