#include<iostream>
using namespace std;

void TOH(int n,int src,int dest, int ext){
    if(n==1) cout<<"move disk from "<<src<<"->"<<dest<<endl;
    else{
        TOH(n-1,src,ext,dest);
        cout<<"move disc from " <<src<<"-> "<<dest<<endl;
        TOH(n-1,ext,dest,src);
    }
}
int main()
{   int n;
    cout<<"enter no of disc "<<endl;
    cin>>n;
    TOH(n,1,2,3);
}