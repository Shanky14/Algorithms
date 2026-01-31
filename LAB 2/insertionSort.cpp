#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;
void insertionS(vector<int> &a,int n)
{
    for(int j=2;j<n;j++)
    {
        int key=a[j];
        int i=j-1;
        while (i>0 && a[i]>key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
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
 /* int target = rand() % 1;
  cout << "key : " << target << endl;*/
  auto start = high_resolution_clock::now();
  insertionS(a,a.size());
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(end - start);
  cout << "Time taken for sorting : " << duration.count() << " ns\n";
    return 0;
}