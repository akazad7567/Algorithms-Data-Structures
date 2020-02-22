#include<bits/stdc++.h>
using namespace std;

vector<long long> trial_division3(long long n) {
    vector<long long> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
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
    re=trial_division3(n);
    for(long long i=0;i<re.size();i++)
    {
        cout<<re[i]<<' ';
    }
    cout<<endl;
    re.clear();
    }
}
