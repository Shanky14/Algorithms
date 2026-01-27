#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;
int linearS(vector<int> &a, int &target, int j)
{
  if (j == a.size())
    return -1;
  if (a[j] == target)
    return j;
  else
  {
    return linearS(a, target, j + 1);
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
  int target = rand() % 100;
  cout << "key : " << target << endl;
  auto start = high_resolution_clock::now();
  int index = linearS(a, target, 0);
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(end - start);
  cout << "index found: " << index << endl;
  cout << "Time taken : " << duration.count() << " ns\n";
  return 0;
}