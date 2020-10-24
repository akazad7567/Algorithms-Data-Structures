#include<bits/stdc++.h>
using namespace std;

int main()
{
    int var=10;
    int *ptr=&var;
    cout<<*ptr<<' '<<var<<endl;//print 10 10
    *ptr=20;
    cout<<*ptr<<' '<<var<<endl;//print 20 20
    var=30;
    cout<<*ptr<<' '<<var<<endl;//print 30 30
    int **ptr1=&ptr;
    **ptr1=40;
    cout<<*ptr<<' '<<**ptr1<<' '<<var<<endl;//print 40 40 40
    var=50;
    cout<<*ptr<<' '<<**ptr1<<' '<<var<<endl;//print 50 50 50
}
