#include<iostream>
#include<vector>
#include<queue>
#include<ctime>
#include<chrono>
using namespace std;
using namespace std::chrono;
void primAlgo(int V, vector<vector<pair<int,int>> >adj)
{
    vector<bool> mstSet(V, false);
   
    priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> >pq;
    int mstCost=0;

    pq.push({0,0}); 

    while(pq.size()>0)
    {
        auto p = pq.top();
        int wt=p.first;
        int u=p.second;
        pq.pop();

        if(!mstSet[u]){
            mstSet[u]=true;
            mstCost+=wt;

            for(int i=0; i<adj[u].size();i++){
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                if(!mstSet[v])
                pq.push({w,v});
            }
        }
    }
    
}
vector<vector<pair<int,int>>> generateGraph(int V)
{
    vector<vector<pair<int,int>>> adj(V);

    int edgesPerVertex = 3; 

    for(int i = 0; i < V; i++){
        for(int k = 0; k < edgesPerVertex; k++){
            int j = rand() % V;

            if(i == j) continue;

            int weight = rand() % 10 + 1;

            adj[i].push_back({j, weight});
            adj[j].push_back({i, weight});
        }
    }
    return adj;
}

int main(){
vector<int> sizes = {100, 500, 1000, 5000, 10000, 15000, 20000, 25000, 30000, 40000,45000, 50000, 55000, 60000, 65000, 70000, 75000, 80000};

    srand(time(0));

    for (int V : sizes)
    {
        double avg = 0;

        for (int run = 0; run < 50; run++) 
        {
            auto adj = generateGraph(V);

            auto start = high_resolution_clock::now();
            primAlgo(V, adj);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(end - start);
            avg += duration.count();
        }

        cout << avg / 50 << ",";
    }

    return 0;
}


