#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> x;
vector<vector<int>> adj;
void NextValue(int k)
{
    do
    {
        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == 0)
        {
            return;
        }
        if (adj[x[k - 1]][x[k]] != 0)
        {
            int j;
            for (j = 1; j <= k-1; j++)
            {
                if (x[j] == x[k])
                {
                    break;
                }
            }
            if (j == k)
            {
                if (k < n || (k == n && adj[x[n]][x[1]] != 0))
                {
                    return;
                }
            }
        }

    } while (1);
}

void Hamiltonian(int k)
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
            cout<<x[1];
            cout << endl;
        }
        else
            Hamiltonian(k + 1);

    } while (1);
}

int main()
{
    cout << "Enter no of vertices : ";
    cin >> n;
   

    adj.resize(n + 1, vector<int>(n + 1));
    x.resize(n + 1);
    cout << "Enter Adjacency Matrix : \n";
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            cin >> adj[i][k];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }
    x[1]=1;
    cout << "HAmiltonian cycles : \n";
    Hamiltonian(2);
    return 0;
}