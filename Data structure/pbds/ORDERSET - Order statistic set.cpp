#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;
using namespace std;

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;

using namespace std;

int main()
{
    order_set os;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char ch;
        int v;
        scanf(" %c %d",&ch,&v);
//        cout<<ch<<' '<<v<<endl;
        if(ch=='I') os.insert(v);
        else if(ch=='D') os.erase(v);
        else if(ch=='C')
        {
            cout<<os.order_of_key(v)<<endl;
        }
        else if(os.size()<v)
        {
            cout<<"invalid\n";
        }
        else
        {
            cout<<*os.find_by_order(v-1)<<endl;
        }
    }
}
