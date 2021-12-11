#include<bits/stdc++.h>
using namespace std;
#define ll  long long

ll ar[100010],fre[100010],cnt=0,ans[100010];
ll block=0;

struct query{
    ll l,r,i;
}Q[200010];

bool cmp(query a,query b){
    if(a.l/block!=b.l/block) return a.l/block<b.l/block;
    return a.r<b.r;
}

void add(ll pos){
    fre[ar[pos]]++;
    if(fre[ar[pos]]==1) cnt++;
}

void remov(ll pos){
    fre[ar[pos]]--;
    if(fre[ar[pos]]==0) cnt--;
}

int main()
{
    ll n,q,i,j;
    scanf("%lld",&n);
    for(i=0;i<n;i++) scanf("%lld",&ar[i]);
    scanf("%lld",&q);
    for(i=0;i<q;i++){
        scanf("%lld",&Q[i].l);
        scanf("%lld",&Q[i].r);
        Q[i].i=i;
        Q[i].l--;
        Q[i].r--;
    }
    block=(int) sqrt(n);
    sort(Q,Q+q,cmp);
    ll ml=0,mr=-1;
    for(i=0;i<q;i++){
        ll L=Q[i].l;
        ll R=Q[i].r;

        while(ml>L) ml--,add(ml);
        while(mr<R) mr++,add(mr);
        while(ml<L) remov(ml),ml++;
        while(mr>R) remov(mr),mr--;
        ans[Q[i].i]=cnt;
    }
    for(i=0;i<q;i++) printf("%lld\n",ans[Q[i].i]);

    return 0;
}

/*
5
1 1 2 1 3
3
1 5
2 4
3 5
*/
