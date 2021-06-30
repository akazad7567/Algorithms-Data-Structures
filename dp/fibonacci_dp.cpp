//time complexity n

#include<bits/stdc++.h>
using namespace std;
#define MAX 500
int dp[MAX];

int fib(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];
}
int main()
{
    for(int i=0;i<100;i++) dp[i]=-1;
    int n;
    cin>>n;
    cout<<fib(n)<<endl;

}
