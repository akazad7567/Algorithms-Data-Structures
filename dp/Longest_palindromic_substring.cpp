//Finding length of longest palindromic substring
#include<bits/stdc++.h>
using namespace std;
#define M 1000
int dp[M][M];
string str;


bool f(int l,int r)
{
    if(l>=r) return true;
    if(dp[l][r]!=-1) return dp[l][r];


    if(str[l]==str[r]) return dp[l][r]=f(l+1,r-1);
    else return dp[l][r]=false;

}
int main()
{
    cin>>str;
    int n=str.size();
    int ans=0;
    string s;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
    {
        string tmp="";
        for(int j=i;j<n;j++)
        {
            tmp+=str[j];
            bool subAns=f(i,j);
            if(subAns and tmp.size()>ans)
            {
                ans=tmp.size();
                s=tmp;
            }
        }
    }

    cout<<s<<' '<<ans<<endl;
}
