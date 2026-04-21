#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct edge
{
    int u, v, weight;

    bool operator>(const edge &second) const
    {
        return weight > second.weight;
    }
};

bool isCycle(int curr, int end, vector<bool> &visit, const vector<vector<int>> &adj)
{
    if (curr == end)
    {
        return true;
    }

    visit[curr] = true;

    for (int neighbour : adj[curr])
    {
        if (!visit[neighbour])
        {
            if (isCycle(neighbour, end, visit, adj))
            {
                return true;
            }
        }
    }
    return false;
}

void kruskal(int v, const vector<edge> &edges)
{
    priority_queue<edge, vector<edge>, greater<edge>> minHeap;

    for (auto e : edges)
    {
        minHeap.push(e);
    }
    vector<vector<int>> adj(v);
    vector<edge> mst;
    int minCost = 0;

    while (!minHeap.empty() && mst.size() < v - 1)
    {
        edge currEdge = minHeap.top();
        minHeap.pop();

        vector<bool> visit(v, false);

        if (!isCycle(currEdge.u, currEdge.v, visit, adj))
        {
            mst.push_back(currEdge);
            minCost += currEdge.weight;

            adj[currEdge.u].push_back(currEdge.v);
            adj[currEdge.v].push_back(currEdge.u);
        }
    }

    if (mst.size() != v-1)
    {
        cout<< "No spanning tree exist \n";
        return;
    }
    cout<<"Edges in MST :\n";
    for(auto e : mst)
    {
        cout<<e.u<<" -> "<< e.v <<" : "<<e.weight <<endl;
    }

    cout<<"Minimum Cost: "<<minCost<<endl;
    
}

int main()
{
    int v = 6;

    vector<edge> edges = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 5},
        {2, 4, 9},
        {3, 4, 7},
        {3, 5, 2},
        {4, 5, 8}
    };

    kruskal(v, edges);

    return 0;
}