#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<cstdlib>
using namespace std;
using namespace chrono;

void maxMin(int a[], int low, int high, int &maxi, int &mini)
{
    if(low == high) 
    {
        maxi = a[low];
        mini = a[low];
    }
    else if (low == high - 1)
    {
        if(a[low] < a[high])
        {
            maxi = a[high];
            mini = a[low];
        }
        else{
            maxi = a[low];
            mini = a[high];
        }
    }
    else
    {
        int mid = low + (high - low) / 2;
        int max1, min1;

        maxMin(a, low, mid, maxi, mini);
        maxMin(a, mid + 1, high, max1, min1);

        if(maxi < max1) maxi = max1;
        if(mini > min1) mini = min1;
    }
}


vector<int> generateArray(int n)
{
    vector<int> arr(n);

   
    for(int i = 0; i < n; i++)
        arr[i] = i + 1;

   
    for(int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }

    return arr;
}

int main()
{
    vector<int> sizes = {100, 500, 1000, 5000, 10000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 60000,70000,80000,90000,95000, 100000};

    srand(time(0));

    for(int n : sizes)
    {
        double avg = 0;

        for(int run = 0; run < 100; run++)
        {
            vector<int> vec = generateArray(n);

            int maxi, mini;

            auto start = high_resolution_clock::now();
            maxMin(vec.data(), 0, n-1, maxi, mini);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(end - start);
            avg += duration.count();
        }

        cout << avg / 100 << ",";
    }

    return 0;
}