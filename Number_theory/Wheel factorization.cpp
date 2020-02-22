#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<long long> trial_division2(long long n) {
    vector<long long> factorization;
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
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
    vector<long long>re;
    long long n;
    while(scanf("%lld",&n)!=EOF){
    re=trial_division2(n);
    for(long long i=0;i<re.size();i++)
    {
        cout<<re[i]<<' ';
    }
    cout<<endl;
    re.clear();
    }
}
