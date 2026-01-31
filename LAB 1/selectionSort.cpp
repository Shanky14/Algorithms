#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

void selectionS(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        int j=i;
        for (int k = i+1; k < a.size(); k++)
        {
            if(a[k]<a[j])
            j=k;
        }
        swap(a[j],a[i]);
    }
    
}
int main()
{
      srand(time(0));
  vector<int> a;
  int n;
  cout << "no of elements:\n";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    a.push_back(rand());
  }
  auto start = high_resolution_clock::now();
  selectionS(a);
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(end - start);
  cout << "Time taken for sorting : " << duration.count() << " ns\n";
    return 0;
}
