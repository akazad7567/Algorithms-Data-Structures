#include<bits/stdc++.h>
using namespace std;

struct segtree
{
    int size=1;
    vector<int>values;
    void init(int n)
    {
        size=1;
        while(size<n) size*=2;
        values.assign(2*size,0);
    }
    void build(vector<int>&a,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            if(lx<(int) a.size()) values[x]=a[lx];
            return;
        }
        int m=(rx+lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        values[x]=values[2*x+1]+values[2*x+2];
    }
    void build(vector<int>&a)
    {
        build(a,0,0,size);
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
        values[x]=values[2*x+1]+values[2*x+2];
    }
    void set(int i,int v)
    {
        set(i,v,0,0,size);
    }

    int cal(int k,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            return lx;
        }
        int m=(rx+lx)/2;
        int l=values[2*x+1];
        if(k<l) return cal(k,2*x+1,lx,m);
        else return cal(k-l,2*x+2,m,rx);

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
        int i,k;
        scanf("%d %d",&i,&k);
        if(i==1)
        {
            a[k]=1-a[k];
            st.set(k,a[k]);
        }
        else
        {
            printf("%d\n",st.cal(k));
        }
    }
}
