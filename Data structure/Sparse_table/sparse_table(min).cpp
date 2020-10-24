#include<bits/stdc++.h>
using namespace std;
#define MAXN 30
#define MAX 1000000
long long st[MAX][MAX];
long long ar[MAX];
int lg[MAX];

void ini()
{
    for(int i=2;i<MAX;i++)
    {
        lg[i]=lg[i/2]+1;
    }
}
void sparse_table(int N,int K)
{
    for(int i=0;i<N;i++)
    {
        st[i][0]=ar[i];
    }

    for(int j=1;j<K;j++)
    {
        for(int i=0;i<N;i++)
        {
            st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
//            cout<<i<<"-> "<<j<<"= "<<st[i][j]<<endl;

        }
//        cout<<endl;
    }
}

long long get(int l,int r)
{
    int j=lg[r-l+1];
    long long val=min(st[l][j],st[r-(1<<j)+1][j]);
    return val;
}
int main()
{
    ini();
    int n,k;
    scanf("%d",&n);
    k=log2(n)+1;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&ar[i]);
    }
    sparse_table(n,k);
    int q;
    scanf("%d",&q);

    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        cout<<get(l,r)<<endl;

    }
}
