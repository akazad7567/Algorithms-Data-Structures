#include<bits/stdc++.h>
using namespace std;
vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
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
    re=trial_division1(n);
    for(long long i=0;i<re.size();i++)
    {
        cout<<re[i]<<' ';
    }
    cout<<endl;
    re.clear();
    }
}
