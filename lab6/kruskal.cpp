#include <iostream>
#include <vector>
#include <queue>
#include<chrono>
using namespace std;
using namespace std::chrono ;
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
vector<edge> generateEdges(int v, int e)
{
    vector<edge> edges;

    while (edges.size() < e)
    {
        int u = rand() % v;
        int vtx = rand() % v;

        if (u == vtx) continue; 
        int wt = rand() % 100 + 1;
        edges.push_back({u, vtx, wt});
    }

    return edges;
}

int main()
{
    vector<int> sizes = {100, 500, 1000, 3000, 5000, 7000, 10000};

    srand(time(0));

    for (int v : sizes)
    {
        int e = v * 2; 
        double avg = 0;

        for (int run = 0; run < 20; run++)
        {
            vector<edge> edges = generateEdges(v, e);

            auto start = high_resolution_clock::now();
            kruskal(v, edges);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(end - start);
            avg += duration.count();
        }

        cout << avg / 20 << ",";
    }

    return 0;
}