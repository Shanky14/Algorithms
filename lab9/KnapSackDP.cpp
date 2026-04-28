#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

void generateItems(int n, vector<int>& wt, vector<int>& val)
{
    wt.clear();
    val.clear();

    for (int i = 0; i < n; i++)
    {
        wt.push_back(rand() % 50 + 1);
        val.push_back(rand() % 100 + 1);
    }
}

int main()
{
    vector<int> sizes = {100, 200, 500, 1000, 2000, 5000, 7000, 10000};

    srand(time(0));

    for (int n : sizes)
    {
        int W = n * 2;
        double avg = 0;

        vector<int> wt, val;

        for (int run = 0; run < 20; run++)
        {
            generateItems(n, wt, val);

            auto start = high_resolution_clock::now();
            knapsack(W, wt, val, n);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(end - start);
            avg += duration.count();
        }

        cout << avg / 20 << ",";
    }

    return 0;
}