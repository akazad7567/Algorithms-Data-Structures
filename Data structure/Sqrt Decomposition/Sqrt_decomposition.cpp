#include<bits/stdc++.h>
using namespace std;
typedef	    long long       ll;

ll ar[10000],block[100],bs,input[10000]; // bs->block size

void update(ll idx,ll val){
    ll bn=idx/bs; // block number
    block[bn]+=val-ar[idx];
    ar[idx]+=val;
}

ll query(ll l,ll r){
    ll sum=0;
    while(l<r and l%bs!=0 and l!=0){
        sum+=ar[l];
        l++;
    }
    while(l+bs<=r){
        sum+=block[l/bs];
        l+=bs;
    }
    while(l<=r){
        sum+=ar[l];
        l++;
    }
    return sum;
}

void preproces(ll n){
    ll blk_idx=-1;
    bs=sqrt(n);
    for(ll i=0;i<n;i++){
        ar[i]=input[i];
        if(i%bs==0) blk_idx++;
        block[blk_idx]+=ar[i];
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    ll a,b,c=0,i,j,t,k,lie,sm=0,m,n,o,x,y,q,z;
    scanf("%lld",&n);
    for(i=0;i<n;i++) scanf("%lld",&input[i]);
    preproces(n);
    for(i=0;i<sqrt(n);i++) cout<<block[i]<<' ';
    scanf("%lld",&q);

    update(1,10);
    while(q--){
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",query(a,b));
    }

    return 0;
}
