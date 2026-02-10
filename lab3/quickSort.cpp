#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
using namespace std;
using namespace std::chrono;
int partitionFunc(vector<int> &arr, int s, int e)
{
    int m = s + (e - s) / 2;
    int index = s;

    for (int i = s; i <= e; i++)
    {
        if (arr[i] < arr[m])
            index++;
    }

    swap(arr[m], arr[index]);

    int l = s;
    int h = e;

    while (l < index && h > index)
    {
        while (arr[l] < arr[index])
            l++;
        while (arr[h] > arr[index])
            h--;
        if (l < h)
        {
            swap(arr[l], arr[h]);
            l++;
            h--;
        }
    }
    return index;
}

void quickSort(vector<int> &arr, int s, int e)
{
    if (s < e)
    {
        int j = partitionFunc(arr, s, e);
        quickSort(arr, s, j - 1);
        quickSort(arr, j + 1, e);
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

            auto start = high_resolution_clock::now();
            quickSort(arr, 0, arr.size() - 1);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(end - start);
            avg += duration.count();
        }

        cout << avg / 1000 << ",";
    }

    return 0;
}
