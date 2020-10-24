#include<bits/stdc++.h>
using namespace std;

#define MAXN 30
long long st[MAXN][1000000];
long long ar[1000000];

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
            st[i][j]=st[i][j-1]+st[i+(1<<j-1)][j-1];
        }
    }
}

long long sum(int l,int r,int k)
{
    long long sum=0;
    for(int j=k;j>=0;j--)
    {
        if(1<<j <= r-l+1)
        {
            sum+=st[l][j];
            l+=1<<j;
        }
    }
    return sum;

}
int main()
{
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
        cout<<sum(l,r,k)<<endl;
    }
}
