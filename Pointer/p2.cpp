#include<bits/stdc++.h>
using namespace std;

int main()
{
    int var=10;
    int *ptr;//since there is * in declaration, ptr
    // becomes a pointer varaible (a variable
    // that stores address of another variable)
    ptr=&var;
    //printf("%d\n",&var);
    printf("%d\n",*ptr);
}
