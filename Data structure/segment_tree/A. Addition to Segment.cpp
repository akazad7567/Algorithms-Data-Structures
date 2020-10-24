#include<bits/stdc++.h>
using namespace std;

struct segtree
{
    int size;
    vector<int>operation;
    void init(int n)
    {
        size=1;
        while(size<n) size*=2;
        operation.assign(2*size,0);
    }
    void set(int l,int r,int v,int x,int lx,int rx)
    {
//        cout<<lx<<' '<<rx<<' '<<x<<endl;
        if(l>=rx || r<=lx) return;
        if(l<=lx and r>=rx)
        {
            operation[x]+=v;
//            cout<<x<<"->"<<operation[x]<<endl;
            return;
        }
        int m=(lx+rx)/2;
        set(l,r,v,2*x+1,lx,m);
        set(l,r,v,2*x+2,m,rx);
    }

    void set(int l,int r,int v)
    {
        set(l,r,v,0,0,size);
    }

    long long get(int i,int x,int lx,int rx)
    {
//        cout<<x<<endl;
        if(rx-lx==1)
        {
            return operation[x];
        }
        int m=(rx+lx)/2;
        long long res;
        if(i<m)
        {
            res=get(i,2*x+1,lx,m);
        }
        else res=get(i,2*x+2,m,rx);
//        cout<<x<<"->>"<<operation[x]<<endl;
        return res+operation[x];
    }
    long long get(int i)
    {
        return get(i,0,0,size);
    }
};

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int>a(n);
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
            st.set(l,r,v);

        }
        else
        {
            int i;
            scanf("%d",&i);
            printf("%lld\n",st.get(i));
        }
    }
}
