#include<bits/stdc++.h>
using namespace std;
#define M 500
int dp[M][M];

int main()
{
    int n,m;
    string s1,s2;
    cin>>s1>>s2;
    n=s1.size(),m=s2.size();

    for(int i=0;i<n;i++) dp[i][m]=0;
    for(int i=0;i<m;i++) dp[n][i]=0;

    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(s1[i]==s2[j])
            {
                dp[i][j]=dp[i+1][j+1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    cout<<dp[0][0]<<endl;


}
