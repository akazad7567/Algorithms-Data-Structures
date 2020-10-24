//substring search
#include<bits/stdc++.h>
using namespace std;
vector<int>pi(1000000);

void prefix_function(string s)
{
    int n=s.size();
    for(int i=1;i<n;i++)
    {
        int j=pi[i-1];
        while(j>0 and s[i]!=s[j]) j=pi[j-1];

        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
//    for(int i=0;i<n;i++) cout<<pi[i]<<' ';
//    cout<<endl;
}

int main()
{
//    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string s;
        cin>>s;
        prefix_function(s);
        int sz=s.size();
        int ans=0;

        for(int i=0;i<sz;i++)
        {

                if(sz-i==pi[sz-1] and i<=pi[sz-1] and pi[sz-1]%i==0)
                {
//                    cout<<sz-i<<' '<<pi[sz-1]<<endl;
                    ans=i;
                    break;
                }

        }
        if(ans) printf("%d\n",ans);
        else printf("%d\n",sz);
        if(t>0) printf("\n");
        pi.clear();
    }
}
