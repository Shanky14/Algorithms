#include<iostream>
#include<vector>
using namespace std;
void permGen(vector<char> &a,int k,int n)
{
    if(k==n) 
    {
        for (char c : a)
            cout << c;
        cout << endl;
        return;
    }
    else{
        for(int i=k;i<n;i++)
        {
            swap(a[i],a[k]);
            permGen(a,k+1,n);
            swap(a[i],a[k]);
        }
    }
} 
int main()
{
    int n;
    cout<<"enter no of char in string\n";
    cin>>n;
    vector<char> a(n);
    cout<<"input string :\n";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];   
    }
    cout<<"Permutation of string : \n";
    permGen(a,0,n);
    return 0;
}