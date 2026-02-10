#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;
void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= end)
        temp.push_back(arr[j++]);

    for (int idx = 0; idx < temp.size(); idx++)
        arr[st + idx] = temp[idx];
}

void mergeSort(vector<int> &arr, int st, int end)
{
    if (st >= end)
        return;

    int mid = st + (end - st) / 2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, st, mid, end);
}

int main()
{
    srand(time(0));
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
            auto start = high_resolution_clock::now();
            mergeSort(arr, 0, arr.size() - 1);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(end - start);
            avg += duration.count();
        }

        cout << avg / 1000 << ",";
    }

    return 0;
}
