#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
void bubbleS(vector<pair<float,float>> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size()-i-1; j++)
        {
            float r1=a[j].first/a[j].second;
            float r2=a[j+1].first/a[j+1].second;

            if (r1<r2)
            {
                swap(a[j],a[j+1]);
            }
            
        }
    }
    
}
float knapSack(vector<pair<float,float>> &a,int capacity)
{
    bubbleS(a);
    float totalValue=0;
    //float r[5];
    for (int j = 0; j< a.size(); j++)
    {
        int value=a[j].first;
        int weight=a[j].second;

        if(capacity>=weight)
        {
            capacity-=weight;
            totalValue+=value;
        }
        else
        {
            totalValue+=((float)value/weight)*capacity;
        }
    }
    return totalValue;
}

vector<pair<float,float>> generateItems(int n)
{
    vector<pair<float,float>> items;

    for(int i = 0; i < n; i++)
    {
        float value = rand() % 1000 + 1;  
        float weight = rand() % 50 + 1;    

        items.push_back({value, weight});
    }

    return items;
}

int main()
{
    vector<int> sizes = {100, 500, 1000, 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000};

    srand(time(0));

    for(int n : sizes)
    {
        double avg = 0;

        for(int run = 0; run < 50; run++)
        {
            auto items = generateItems(n);
            int capacity = rand() % (n * 10) + 50;

            auto start = high_resolution_clock::now();
            float ans = knapSack(items, capacity);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(end - start);
            avg += duration.count();
        }

        cout << avg / 50 << ",";
    }

    return 0;
}