#include<iostream>
#include<vector>
using namespace std;
void hornor(int k, int m, vector<int> &a)
{

    if(k==m-1)
    {
        cout<<a[k];
        return;
    }
    cout<<"(";
    hornor(k+1,m,a);
    cout<<"x + "<<a[k]<<")";
}
int main()
{
    int n;
    cout<<"enter value for n :\n";
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    hornor(0,a.size(),a);
    return 0;
}