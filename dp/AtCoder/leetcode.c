class Solution {
public:
    int dp[510][510];
    void ini()
    {
        for(int i=0;i<505;i++)
        {
            for(int j=0;j<505;j++)
            {
                dp[i][j]=-1;
            }
        }
    }
    int f(string s1,string s2,int i,int j)
    {
        if(s1.size()==i or s2.size()==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j])
        {
            ans=f(s1,s2,i+1,j+1);
        }
        else
        {
            int v1=1+f(s1,s2,i+1,j);
            int v2=1+f(s1,s2,i,j+1);
            int v3=1+f(s1,s2,i+1,j+1);
            ans=min(v1,v2,v3);
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        ini();
        return f(word1,word2,0,0);

    }
};
