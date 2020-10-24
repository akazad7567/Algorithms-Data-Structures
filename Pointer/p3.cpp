#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v[3]={10,20,30};
    int *ptr;
    ptr=v;
    for(int i=0;i<3;i++)
    {
        printf("%d ",*ptr);
        //printf("%d\n",ptr);
        ptr++;
    }
    printf("\n");
    ptr=v;
    printf("%d %d %d \n",ptr[0],ptr[1],ptr[2]);
    int var=20;
    ptr=&var;
    cout<<*ptr<<endl;
    var=30;
    cout<<var<<endl;
    cout<<*ptr<<endl;
}
