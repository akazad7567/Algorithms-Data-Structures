//How many permutation of S (|S|<=10,each digit are unique number) are divisible
//by D(<=1000)

#include<bits/stdc++.h>
using namespace std;
int dp[1<<10+2][1010];
string s;
int d;

int f(int msk,int mod)
{
    int pos=__builtin_popcount(msk);
    if(pos==s.size())
    {
        if(mod==0) return 1;
        else return 0;
    }
    if(dp[msk][mod]!=-1) return dp[msk][mod];
    int ret=0;

    for(int i=0;i<s.size();i++)
    {
        if((1<<i)&msk) continue;
        int val=f(msk|(1<<i),(mod*10+(s[pos]-'0'))%d);
        ret+=val;
    }
    return dp[msk][mod]=ret;
}
int main()
{
    cin>>s>>d;

    memset(dp,-1,sizeof dp);

    cout<<f(0,0)<<endl;

}
