#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int DFS(vector<vector<int>> &cost, vector<bool> &vis, int last, int count)
{
    int n = cost.size();

    if (count == n)
        return cost[last][0];

    int minCost = (int)1e9;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            minCost = min(minCost, cost[last][i] + DFS(cost, vis, i, count));
            vis[i] = false;
        }
    }
    return minCost;
}

int tsp(vector<vector<int>> &cost)
{
    int n = cost.size();

    vector<bool> vis(n, false);
    vis[0] = true;

    return DFS(cost, vis, 0, 1);
}

int main()
{
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    int res = tsp(cost);
    cout << res;
    return 0;
}