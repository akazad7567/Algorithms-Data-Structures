#include<bits/stdc++.h>
using namespace std;

struct item
{
    int m,c;
};

struct segtree
{
    int size;
    vector<item>values;
    item jinish={INT_MAX,0};
    item merge(item a,item b)
    {
        if(a.m<b.m) return a;
        if(b.m<a.m) return b;
        return {a.m,a.c+b.c};
    }
    item single(int v)
    {
        return {v,1};
    }
    void init(int n)
    {
        size=1;
        while(size<n) size*=2;
        values.resize(size*2);
    }
    void build(vector<int>&a,int x,int lx,int rx)
    {

        if(rx-lx==1)
        {
            if(lx<(int)a.size()) values[x]=single(a[lx]);
            return;
        }
        int m=(rx+lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        values[x]=merge(values[2*x+1],values[2*x+2]);
    }

    void build(vector<int>&a)
    {
        build(a,0,0,size);
    }

    void set(int i,int v,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            values[x]=single(v);
            return;
        }
        int m=(rx+lx)/2;
        if(i<m) set(i,v,2*x+1,lx,m);
        else set(i,v,2*x+2,m,rx);
        values[x]=merge(values[2*x+1],values[2*x+2]);

    }
    void set(int i,int v)
    {
        set(i,v,0,0,size);
    }
    item cal(int l,int r,int x,int lx,int rx)
    {
        if(l>=rx || r<=lx) return jinish;
        if(l<=lx && r>=rx) return values[x];
        int m=(rx+lx)/2;
        item s1=cal(l,r,2*x+1,lx,m);
        item s2=cal(l,r,2*x+2,m,rx);
        return merge(s1,s2);
    }
    item cal(int l,int r)
    {
        return cal(l,r,0,0,size);
    }
};

int main()
{
    int n,m;
    segtree st;
    scanf("%d %d",&n,&m);
    st.init(n);
    vector<int>a(n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    st.build(a);

    while(m--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int i,v;
            scanf("%d %d",&i,&v);
            st.set(i,v);
        }
        else
        {
            int l,r;
            scanf("%d %d",&l,&r);
            auto res=st.cal(l,r);
            printf("%d %d\n",res.m,res.c);
        }
    }

}
