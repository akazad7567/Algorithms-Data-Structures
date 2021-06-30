#include<bits/stdc++.h>
using namespace std;
#define M 500
typedef long long ll;
int dp[M][M];
string s1,s2;

int lcs(int i,int j)
{
    if(i==s1.size() or j==s2.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(s1[i]==s2[j])
    {
        ans=1+lcs(i+1,j+1);
    }
    else
    {
        int v1=lcs(i+1,j);
        int v2=lcs(i,j+1);
        ans=max(v1,v2);
    }
    dp[i][j]=ans;
    return dp[i][j];
}
int main()
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<M;j++)
        {
            dp[i][j]=-1;
        }
    }

    cin>>s1>>s2;
    cout<<lcs(0,0)<<endl;

}
