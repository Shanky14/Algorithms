#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> x;
vector<int> w;
void sumofSubset(int s, int k, int r)
{
    x[k] = 1;

    if (s + w[k] == m)
    {
        for (int i = 0; i <= k; i++)
        {
            if (x[i] == 1)
            {
                cout << w[i] << " ";
            }
        }
        cout << endl;
    }
    else if (k + 1 < n && s + w[k] + w[k + 1] <= m)
    {
        sumofSubset(s + w[k], k + 1, r - w[k]);
    }

    if (k+1<n && s + r - w[k] >= m && s + w[k] <= m)
    {
        x[k] = 0;
        sumofSubset(s, k + 1, r - w[k]);
    }
}

int main()
{
    cout<<"Enter no of elements : ";
    cin>>n;
    w.resize(n);
    x.resize(n);

    cout<<"Enter the weights : ";
    int totalSum=0;
    for (int i = 0; i < n; i++)
    {
        cin>> w[i];
        totalSum+=w[i];
    }
    
    cout<<"\nEnter target weight : ";
    cin>>m;
  

    sumofSubset(0,0,totalSum);
    return 0;
}