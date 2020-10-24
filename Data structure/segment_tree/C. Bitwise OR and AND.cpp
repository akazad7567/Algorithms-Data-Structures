#include<bits/stdc++.h>
using namespace std;
typedef int ll;
struct segtree
{
    int size;
    vector<ll>operation,values;
    ll neutral=-1;
    void init(int n)
    {
        size=1;
        while(size<n) size*=2;
        operation.assign(2*size,0LL);
        values.assign(2*size,0LL);
    }

    void modify(int l,int r,int v,int x,int lx,int rx)
    {
//        cout<<x<<endl;
        if(l>=rx || r<=lx) return;
        if(l<=lx and rx<=r)
        {
            operation[x]|=v;
            values[x]|=v;
            return;
        }

        int m=(rx+lx)/2;
        modify(l,r,v,2*x+1,lx,m);
        modify(l,r,v,2*x+2,m,rx);
        values[x]=values[2*x+1] & values[2*x+2];
        values[x]=values[x] | operation[x];

    }
    void modify(int l,int r,int v)
    {
        modify(l,r,v,0,0,size);
    }

    ll get(int l,int r,int x,int lx,int rx)
    {
        if(l>=rx || r<=lx) return neutral;
        if(l<=lx and r>=rx) return values[x];
        int m=(rx+lx)/2;
        int r1,r2,res;
        r1=get(l,r,2*x+1,lx,m);
        r2=get(l,r,2*x+2,m,rx);
        res=r1&r2;
        res=res|operation[x];
        return res;
    }
    ll get(int l,int r)
    {
        return get(l,r,0,0,size);
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
            int l,r ;
            scanf("%d %d",&l,&r);
            printf("%d\n",st.get(l,r));

        }
    }

}
