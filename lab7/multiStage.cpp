#include <iostream>
#include <climits>
#include<ctime>
using namespace std;

#define MAX 10
int findStages(int c[][MAX], int n)
{
    int stage[MAX];

    stage[n] = 1;

    for (int i = n - 1; i >= 1; i--)
    {
        int maxStage = 0;

        for (int j = i + 1; j <= n; j++)
        {
            if (c[i][j] != 0)
            {
                if (stage[j] > maxStage)
                    maxStage = stage[j];
            }
        }

        stage[i] = maxStage + 1;
    }

    return stage[1];
}
void forwardGraph(int c[][10], int n, int k)
{
    int cost[10], d[10];

    cost[n] = 0;

    for (int j = n - 1; j >= 1; j--)
    {
        cost[j] = INT_MAX;

        for (int r = j + 1; r <= n; r++)
        {
            if (c[j][r] != 0)
            {
                if (cost[r]!= INT_MAX && c[j][r] + cost[r] < cost[j])
                {
                    cost[j] = c[j][r] + cost[r];
                    d[j] = r;
                }
            }
        }
    }
    cout << "Minimum Cost: " << cost[1] << endl;
}

void backwardGraph(int c[][10], int n, int k)
{
    int cost[10], d[10];

    cost[1] = 0;
    for (int j = 2; j <= n; j++)
    {
        cost[j] = INT_MAX;

        for (int r = 1; r < j; r++)
        {
            if ( c[r][j] != 0)
            {
                if (cost[r]!= INT_MAX && c[r][j] + cost[r] < cost[j])
                {
                    cost[j] = c[r][j] + cost[r];
                    d[j] = r;
                }
            }
        }
    }
    cout << "Minimum Cost for Bgraph: " << cost[n] << endl;
}
int main()
{
    int v, w;
    cout << "Enter no of vertices\n";
    cin >> v;
    int c[10][10];

    srand(time(0)); 

for (int i = 1; i <= v; i++)
{
    for (int j = 1; j <= v; j++)
    {
        if (i == j)
        {
            c[i][j] = 0;
        }
        else if (j > i)   
        {
            int x = rand() % 10;  

            if (x < 3)
                c[i][j] = 0;      
            else
                c[i][j] = x + 1;  
        }
        else
        {
            c[i][j] = 0; 
        }
    }
}
cout << "\nMatrix:\n";
for (int i = 1; i <= v; i++)
{
    for (int j = 1; j <= v; j++)
        cout << c[i][j] << " ";
    cout << endl;
}

    int k= findStages(c,v);

    forwardGraph(c, v, k);
    backwardGraph(c, v, k);

    return 0;
}
