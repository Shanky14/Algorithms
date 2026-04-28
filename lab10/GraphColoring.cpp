#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n, m;
vector<int> x;
vector<vector<int>> adj;
void NextValue(int k)
{
    do
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
        {
            return;
        }
        int j;
        for (j = 1; j <= n; j++)
        {
            if (adj[k][j] == 1 && x[k] == x[j])
            {
                break;
            }
        }
        if (j == n+1)
            return;

    } while (1);
}

void mColoring(int k)
{
    do
    {
        NextValue(k);

        if (x[k] == 0)
        {
            return;
        }
        if (k == n)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << x[i] << " ";
            }
            cout << endl;
        }
        else
            mColoring(k + 1);

    } while (1);
}

int main()
{
    cout << "Enter no of vertices : ";
    cin >> n;
    cout << "Enter no of colors available : ";
    cin >> m;

    adj.resize(n + 1, vector<int>(n + 1));
    cout<<"Enter Adjacency Matrix : \n";
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            cin >> adj[i][k];
        }
    }

    x.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }
    cout<<"Solution : \n";
    mColoring(1);
    return 0;
}