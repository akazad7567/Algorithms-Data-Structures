#include<bits/stdc++.h>
using namespace std;
#define M 500
int dp[M];

int iterative_dp(vector<int>&vec)
{
    int n=vec.size();
    for(int i=n-1;i>=0;i--)
    {
        int ans=0;
        for(int j=i+1;j<n;j++)
        {
            if(vec[i]<vec[j])
            {
                ans=max(ans,dp[j]);
            }
        }
        dp[i]=ans+1;
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dp[i]);
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<int>vec;
    fill(vec.begin(),vec.end(),0);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        vec.push_back(a);
    }


    cout<<iterative_dp(vec)<<endl;
}

/*
7
5 0 9 2 7 3 4
*/
