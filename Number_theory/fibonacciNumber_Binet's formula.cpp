#include<bits/stdc++.h>
using namespace std;
int main()
{

    while(true){

    double d=5,n,r,r2;
    cin>>n;
    r=(pow(((1+sqrt(d))/2.0),n)-pow(((1-sqrt(d))/2.0),n))/sqrt(d);//first way
    r2=pow(((1+sqrt(d))/2.0),n)/sqrt(d);//second way
    cout<<n<<"->"<<r<<endl;
    double d1,d2;
    //find nearest integer
    d1=ceil(r2)-r2;
    d2=r2-floor(r2);

    if(d1<d2)
    cout<<n<<"->"<<ceil(r2)<<endl;
    else    cout<<n<<"->"<<floor(r2)<<endl;
    }

}
