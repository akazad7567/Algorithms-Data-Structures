#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segtree
{
    int size;
    vector<ll>values,operation;
    ll NO_OPERATION=LLONG_MAX;
    ll NEUTRAL=0LL;
    void init(int n)
    {
        size=1;
        while(size<n) size*=2;
        values.assign(2*size,0LL);
        operation.assign(2*size,0LL);
    }

    ll apply_mod(ll a,ll b,ll len)
    {
        if(b==NO_OPERATION) return a;
        return b*len;
    }

    void apply_mod_op(ll &a,ll b,ll len)
    {
        ll a1=a;
        a=apply_mod(a,b,len);
    }

    ll cal(ll a,ll b)
    {
        return a+b;
    }
    void propagation(int x,int lx,int rx)
    {
        if(rx-lx==1) return;
        int m=(rx+lx)/2;
        apply_mod_op(operation[2*x+1],operation[x],1);
        apply_mod_op(values[2*x+1],operation[x],m-lx);
        apply_mod_op(operation[2*x+2],operation[x],1);
        apply_mod_op(values[2*x+2],operation[x],rx-m);
        operation[x]=NO_OPERATION;
    }

    void modify(int l,int r,int v,int x,int lx,int rx)
    {
        propagation(x,lx,rx);
        if(l>=rx || r<=lx) return;
        if(l<=lx and r>=rx)
        {
            apply_mod_op(operation[x],v,1);
            apply_mod_op(values[x],v,rx-lx);
            return;
        }
        int m=(rx+lx)/2;
        modify(l,r,v,2*x+1,lx,m);
        modify(l,r,v,2*x+2,m,rx);
        values[x]=cal(values[2*x+1],values[2*x+2]);
//        cout<<x<<"->:"<<values[2*x+1]<<' '<<values[2*x+2]<<endl;
    }

    void modify(int l,int r,int v)
    {
        modify(l,r,v,0,0,size);
    }

    ll sum(int l,int r,int x,int lx,int rx)
    {
        propagation(x,lx,rx);
//        cout<<x<<"->"<<values[x]<<endl;
        if(l>=rx || r<=lx) return NEUTRAL;
        if(l<=lx and r>=rx)
        {
            return values[x];
        }
        int m=(rx+lx)/2;
        ll r1,r2,res;
        r1=sum(l,r,2*x+1,lx,m);
        r2=sum(l,r,2*x+2,m,rx);
//        cout<<x<<"->> "<<r1+r2<<endl;
        return cal(r1,r2);
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
