#include <iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
#define INF 999999
int minDist(vector<int> &vis, vector<int> &dist, int n)
{
    int minIndex = -1;
    int minValue = INF;

    for (int i = 0; i < n; i++)
    {
        //checking ki visited nhi h or dis[i] < minvlaue se
        if (!vis[i] && dist[i] < minValue)
        {
            minValue = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkastra(int v, vector<vector<int>> &cost, vector<int> &dist, int n)
{
    vector<int> vis(n,0);

   
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        dist[i] = cost[v][i];
    }

    dist[v] = 0;
    vis[v] = 1;

  
    for (int j = 0; j < n - 1; j++)
    {
        int u = minDist(vis, dist, n);
        if(u == -1) break;
        vis[u] = true;

        for (int num = 0; num < n; num++)
        {
            if (!vis[num] && cost[u][num] != INF)
            {
                if (dist[num] > dist[u] + cost[u][num])
                {
                    dist[num] = dist[u] + cost[u][num];
                }
            }
        }
    }
}

 
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> cost(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)
                cost[i][j] = 0;
            else{
                int edge = rand() % 2;
                if(edge)
                    cost[i][j] = rand() % 10 + 1;
                else
                    cost[i][j] = INF;
            }
        }
    }
    return cost;
}


int main()
{
vector<int> sizes = {100, 500, 1000, 5000, 10000, 15000, 20000};

    srand(time(0));

    for (int n : sizes)
    {
        double avg = 0;

        for (int run = 0; run < 20; run++)
        {
            auto cost = generateMatrix(n);
            vector<int> dist(n);

            auto start = high_resolution_clock::now();
            dijkastra(0, cost, dist, n);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(end - start);
            avg += duration.count();
        }

        cout << avg / 20 << ",";
    }

    return 0;
}