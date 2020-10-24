#include<bits/stdc++.h>
using namespace std;
vector<int>pi(1000000);

void prefix_function(string s)
{
    int n=s.size();
    int j=0;
    for(int i=1;i<n;i++)
    {
        j=pi[i-1];
        while(j>0 and s[i]!=s[j]) j=pi[j-1];
        if(s[j]==s[i]) j++;
        pi[i]=j;
    }

    for(int i=0;i<n;i++) cout<<pi[i]<<' ';
    cout<<endl;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string s,p;
        cin>>s;
        cin>>p;
        prefix_function(p);

        int j=0;
        bool b=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==p[j]) j++;
            else
            {
                if(j>0) j=pi[j-1];
            }
            if(p.size()==j)
            {
                b=true;
                break;
            }
        }

        if(b) cout<<"Found\n";
        else cout<<"Not Found\n";
        pi.clear();
    }
}
