#include<iostream>
using namespace std;
int power(int x, int n)
{
    if(n==0) return 1;
    else return x*power(x,n-1);
}
int power1(int x, int n)
{
    if(n==0) return 1;
   int half=power1(x,n/2);
   if(n %2==0)
   return half*half;
   else return 2*half*half;
    }


int main()
{
    cout<<power(2,5);
    cout<<power1(2,4);
    return 0;
}
