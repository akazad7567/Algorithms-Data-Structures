#include<bits/stdc++.h>
using namespace std;

struct item
{
    long long seg,pref,suf,sum;
};
struct segtree
{
    int size;
    vector<item>values;
    item neotral_value={0,0,0,0};
    void init(int n)
    {
        size=1;
        while(size<n) size*=2;
        values.resize(size*2);
    }
    item merge(item a,item b)
    {
        return
        {
            max(a.seg,max(b.seg,a.suf+b.pref)),
            max(a.pref,a.sum+b.pref),
            max(b.suf,b.sum+a.suf),
            a.sum+b.sum
        };
    }
    item single(int v)
    {
        if(v>0)
        return {v,v,v,v};
        else return {0,0,0,v};
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
        if(l>=rx || r<=lx) return neotral_value;
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
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    st.build(a);
    printf("%lld\n",st.cal(0,n).seg);

    while(m--)
    {
        int i,v;
        scanf("%d %d",&i,&v);
        st.set(i,v);
        printf("%lld\n",st.cal(0,n).seg);
    }
}
