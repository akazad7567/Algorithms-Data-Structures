#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


struct segtree
{
    int size;
    vector<ll>values,operation;

    void init(int n)
    {
        size=1;
        while(size<n) size*=2;
        values.assign(2*size,0LL);
        operation.assign(2*size,0LL);
    }

    ll apply_mod(ll a,ll b,ll len)
    {
        return a+(b*len);
    }
    void apply_mod_op(ll &a,ll b,ll len)
    {
        a=apply_mod(a,b,len);
//        cout<<a<<endl;
    }
    ll cal_op(ll a,ll b)
    {
        return a+b;
    }

    void modify(int l,int r,int v,int x,int lx,int rx)
    {
        if(l>=rx || r<=lx) return;
        if(l<=lx and r>=rx)
        {
            apply_mod_op(values[x],v,rx-lx);
            apply_mod_op(operation[x],v,1LL);
            return;
        }
        int m=(lx+rx)/2;
        modify(l,r,v,2*x+1,lx,m);
        modify(l,r,v,2*x+2,m,rx);
        values[x]=cal_op(values[2*x+1],values[2*x+2]);
        apply_mod_op(values[x],operation[x],rx-lx);
//        cout<<x<<' '<<values[x]<<endl;
    }

    void modify(int l,int r,int v)
    {
        modify(l,r,v,0,0,size);
    }

    ll sum(int l,int r,int x,int lx,int rx)
    {
//        cout<<x<<"-> "<<values[x]<<' '<<operation[x]<<endl;
        if(l>=rx || r<=lx) return 0LL;
        if(l<=lx and r>=rx)
        {
            return values[x];
        }
        int m=(lx+rx)/2;
        ll r1=sum(l,r,2*x+1,lx,m);
        ll r2=sum(l,r,2*x+2,m,rx);
        ll res=cal_op(r1,r2);
        apply_mod_op(res,operation[x],min(rx,r)-max(lx,l));
//        cout<<x<<"->>>"<<res<<' '<<operation[x]<<' '<<min(rx,r)<<' '<<max(lx,l)<<endl;
        return res;

    }
    ll sum(int l,int r)
    {
        return sum(l,r,0,0,size);
    }
};


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    segtree st;
    st.init(n);

    while(m--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
//            cout<<"yehe\n";
            int l,r,v;
            scanf("%d %d %d",&l,&r,&v);
            st.modify(l,r,v);

        }
        else
        {
            int l,r;
            scanf("%d %d",&l,&r);
            printf("%lld\n",st.sum(l,r));

        }
    }
}
