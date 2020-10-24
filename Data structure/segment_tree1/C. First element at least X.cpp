#include<bits/stdc++.h>
using namespace std;

typedef int item;
struct segtree
{
    int size=1;
    vector<item>values;
    void init(int n)
    {
        size=1;
        while(size<n) size*=2;
        values.resize(2*size);
    }
    item merge(item a,item b)
    {
        return max(a,b);
    }
    item single(int v)
    {
        return v;
    }
    void build(vector<int>&a,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            if(lx<(int) a.size()) values[x]=single(a[lx]);
            return;
        }
        int m=(rx+lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        values[x]=merge(values[2*x+1],values[2*x+2]);
//        cout<<x<<"->"<<values[x].l<<' '<<values[x].r<<endl;
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

    int cal(int k,int x,int lx,int rx)
    {
//        cout<<x<<"->"<<values[x]<<endl;
        if(values[x]<k) return -1;
        if(rx-lx==1)
        {
            return lx;
        }
        int m=(rx+lx)/2;
        int res=cal(k,2*x+1,lx,m);
        if(res==-1) res=cal(k,2*x+2,m,rx);
        return res;

    }
    int cal(int k)
    {
        return cal(k,0,0,size);
    }
};

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    segtree st;
    st.init(n);
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    st.build(a);
    while(m--)
    {
        int op;
        scanf("%d",&op);
        int i,k;
        if(op==1)
        {
            scanf("%d %d",&i,&k);
            st.set(i,k);
        }
        else
        {
            scanf("%d",&k);
            printf("%d\n",st.cal(k));
        }
    }
}

