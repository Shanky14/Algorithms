#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include<fstream>
using namespace std;
using namespace std::chrono;
int linearS(vector<int> &a, int target, int j)
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
  vector<int> a;
  int n;
  cout << "no of elements:\n";
  cin >> n;
 
  for (int i = 0; i < n; i++)
  {
    a.push_back(i+1);
  }
  srand(time(0));
  for (int i = a.size()-1; i >=0; i--)
  {
    int j=rand()%(i+1);
    swap(a[i],a[j]);
  }
  
  
   ofstream file("linearS1.txt",ios::app);

    // -------- BEST CASE --------
    file << "BEST\n";
    int bestTarget = a[0];
    auto start = high_resolution_clock::now();
    linearS(a, bestTarget, 0);
    auto end = high_resolution_clock::now();
    file << n << " " << duration_cast<nanoseconds>(end - start).count()/1000000 << " ms\n\n";

    // -------- AVERAGE CASE --------
    file << "AVERAGE\n";
    int avgTarget = a[rand() % n];
    start = high_resolution_clock::now();
    linearS(a, avgTarget, 0);
    end = high_resolution_clock::now();
    file << n << " " << duration_cast<nanoseconds>(end - start).count()/1000000 << " ms\n\n";

    // -------- WORST CASE --------
    file << "WORST\n";
    int worstTarget = -1;
    start = high_resolution_clock::now();
    linearS(a, worstTarget, 0);
    end = high_resolution_clock::now();
    file << n << " " << duration_cast<nanoseconds>(end - start).count()/1000000 << " ms\n";

    file.close();

    cout << "Data written to linearS.txt successfully\n";
  return 0;
}