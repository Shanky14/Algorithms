#include <iostream>
#include <vector>
using namespace std;
bool place(int k, int i, vector<int> &x)
{
    for (int j = 0; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return false;
        }
    }
    return true;
}

void NQueen(int k, int n, vector<int> &x)
{
    for (int i = 0; i < n; i++)
    {
        if (place(k, i, x))
        {
            x[k] = i;
            if (k == n - 1)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << x[j] << " ";
                }
                cout << endl;
            }
            else
                NQueen(k + 1, n, x);
        }
    }
}

int main()
{
    int n;
    cout<<"Enter no of queens to be placed : ";
    cin>>n;
    vector<int> X(n);
    NQueen(0,n,X);

    return 0;
}