#include<bits/stdc++.h>
using namespace std;

struct segtree
{
    int size;
    vector<int>values;
    void init(int n)
    {
        size=1;
        while(size<n) size*=2;
        values.assign(size*2,0);
    }
    void set(int i,int v,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            values[x]=v;
            return;
        }
        int m=(rx+lx)/2;
        if(i<m) set(i,v,2*x+1,lx,m);
        else set(i,v,2*x+2,m,rx);
        values[x]=min(values[2*x+1],values[2*x+2]);
    }

    void set(int i,int v)
    {
        set(i,v,0,0,size);
    }
    void build(vector<int>&a,int x,int lx,int rx)
    {
//        cout<<a.size()<<' '<<x<<' '<<rx<<' '<<lx<<endl;
        if(rx-lx==1)
        {
            if(lx<(int)a.size()) values[x]=a[lx];
            return;
        }
        int m=(rx+lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        values[x]=min(values[2*x+1],values[2*x+2]);
    }

    void build(vector<int>&a)
    {
        build(a,0,0,size);
    }
    int cal(int l,int r,int x,int lx,int rx)
    {
        if(l>=rx || r<=lx) return INT_MAX;
        if(lx>=l && rx<=r) return values[x];

        int m=(rx+lx)/2;
        int s1=cal(l,r,2*x+1,lx,m);
        int s2=cal(l,r,2*x+2,m,rx);
        return min(s1,s2);

    }
    int cal(int l,int r)
    {
        return cal(l,r,0,0,size);
    }
};


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    segtree st;
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
            printf("%d\n",st.cal(l,r));
        }
    }
}
