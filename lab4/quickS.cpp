#include<iostream>
#include<vector>
#include<stack>
#include<chrono>
using namespace std;
using namespace std::chrono;
int partition(vector<int> &a,int s, int e)
{
    //int m=s+(e-s)/2;
    int i=s;
    int j=e;
    int pivot = a[s];

    while (i<=j)
    {
        while (a[i]<pivot)
        {
            i++;
        }
        while (a[j]>pivot)
        {
            j--;
        }
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    //swap(a[s],a[j]);
    return i;
    
}
void quickSort(vector<int> &a)
{
    int n=a.size();
    stack<int> st;

    st.push(0);
    st.push(n-1);

    while(!st.empty())
    {
        int high=st.top(); 
        st.pop();
        int low=st.top();
        st.pop();

        int p=partition(a,low,high);

        if(p-1>low)
        {
            st.push(low);
            st.push(p-1);
        }

        if(p<high)
        {
            st.push(p);
            st.push(high);
        }
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
            quickSort(arr);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(end - start);
            avg += duration.count();
        }

        cout << avg / 1000 << ",";
    }

    return 0;
}