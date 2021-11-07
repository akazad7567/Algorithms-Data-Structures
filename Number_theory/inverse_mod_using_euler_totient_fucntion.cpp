//'mod' can be any co prime with 'a'

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1e9+7;

ll phi(ll n)
{
	ll result = n;
	for (ll p = 2; p<= n/p; ++p) {

		if (n % p == 0) {

			while (n % p == 0)
				n /= p;
			result -= result / p;
		}
	}

	if (n > 1)
		result -= result / n;
	return result;
}

ll inverse(ll a,ll m)
{
    if(m==0)
    {
        return 1LL;
    }
    ll r=inverse(a,m/2);
    r=(r*r)%mod;
    if(m&1) r=(r*a)%mod;
    return r;
}

int main()
{
	ll a;
	cin>>a;
    ll phi_of_n=phi(mod);
    cout<<phi_of_n<<endl;

    cout<<inverse(a,phi_of_n-1)<<endl;

	return 0;
}

