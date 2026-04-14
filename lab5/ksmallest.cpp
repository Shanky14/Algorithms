#include<iostream>
#include<vector>
#include<chrono>
#include<cstdlib>
using namespace std;
using namespace chrono;

int partition(int a[], int s, int e)
{
    int pivot = a[s];
    int i = s, j = e;

    while(i <= j)
    {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;

        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    return i - 1;
}

int ksmallest(int a[], int s, int e, int k)
{
    while(s <= e)
    {
        int p = partition(a, s, e);

        if(p == k - 1)
            return a[p];
        else if(p < k - 1)
            s = p + 1;
        else
            e = p - 1;
    }
    return -1;
}

// Unique random array
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
    vector<int> sizes = {100, 500, 1000, 5000, 10000, 20000, 25000, 30000, 35000, 40000, 45000, 50000};

    srand(time(0));
    int k; 
    cout<<"Kth element :\n ";
    cin>>k;

    for(int n : sizes)
    {
        double avg = 0;

        for(int run = 0; run < 100; run++)
        {
            vector<int> vec = generateArray(n);

            auto start = high_resolution_clock::now();
            int ans = ksmallest(vec.data(), 0, n - 1, k);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(end - start);
            avg += duration.count();
        }

        cout << avg / 100 << ",";
    }

    return 0;
}