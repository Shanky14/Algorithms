#include <iostream>
#include <vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
int binaryS(vector<int> &a, int s, int e, int target)
{
    while (s < e)
    {
        int m = s+(e-s)/3;

        if (a[m] == target)
            return m;
        else if (a[m] < target)
            return binaryS(a, m + 1, e, target);
        else
            return binaryS(a, s, m - 1, target);
    }
}
int main()
{
    vector<int> sizes = {100, 500, 1000, 5000, 10000, 15000, 20000, 25000, 30000,35000,40000,45000};

    for (int n : sizes)
    {
        double avg = 0;
        for (int run = 0; run < 1000; run++)
        {
            vector<int> arr;

            for (int i = 0; i < n; i++)
                arr.push_back(i + 1);

            for (int i = arr.size() - 1; i >= 0; i--)
            {
                int j = rand() % (i + 1);
                swap(arr[i], arr[j]);
            }
            int target = arr[n];
            auto start = high_resolution_clock::now();
            binaryS(arr,0,n-1,target);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(end - start);
            avg += duration.count();
        }

        cout << avg / 1000 << ",";
    }

    return 0;
}
