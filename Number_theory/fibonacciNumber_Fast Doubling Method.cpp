#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1000000007;

pair<ll, ll> fib (ll n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    ll c = (p.first%mod) * ((2 * p.second%mod - p.first%mod)%mod);
    ll d = p.first%mod * p.first%mod + p.second%mod * p.second%mod;
    if (n & 1)
        return {d%mod, (c + d)%mod};
    else
        return {c%mod, d%mod};
}

int main()
{
    ll n,t;
    cin>>t;
    while(t--){
    cin>>n;
    pair<ll, ll> p=fib(n);
   cout<<p.first<<' '<<p.second<<endl;
}
}
