#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>primes;
//long long binpower(long long a, long long b, long long m) {
//    a %= m;
//    long long res = 1;
//    while (b > 0) {
//        if (b & 1)
//            res = res * a % m;
//        a = a * a % m;
//        b >>= 1;
//    }
//    return res;
//}
//bool probablyPrimeFermat(int n, int iter=5) {
//    if (n < 4)
//        return n == 2 || n == 3;
//
//    for (int i = 0; i < iter; i++) {
//        int a = 2 + rand() % (n - 3);//We pick an integer 2≤a≤p−2
//        if (binpower(a, n - 1, n) != 1)//  a^p−1 !≡1 mod p we know that p cannot be a prime number
//            return false;
//    }
//    return true;
//}
void sieve(ll n)
{
    bool b[n+1];
    memset(b,true,sizeof b);
    b[0]=false;
    b[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(b[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                b[j]=false;
            }
        }
    }
    primes.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(b[i]) primes.push_back(i);
    }
}

vector<long long> trial_division4(long long n) {
    vector<long long> factorization;
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main()
{
    sieve(1000000);
    vector<long long>re;
    long long n;
    while(scanf("%lld",&n)!=EOF){
    re=trial_division4(n);
    for(long long i=0;i<re.size();i++)
    {
        cout<<re[i]<<' ';
    }
    cout<<endl;
    re.clear();
    }
}
