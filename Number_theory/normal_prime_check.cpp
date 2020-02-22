#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    bool b;
    while(scanf("%d",&n)!=EOF)
    {
        b=isPrime(n);
        if(b) cout<<"ok\n";
    }
}
