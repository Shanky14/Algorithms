#include<iostream>
#include<vector>
#include<chrono>
#include<fstream>
using namespace std;
using namespace std::chrono;

void bubbleS(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size()-i-1; j++)
        {
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
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
  bubbleS(a);
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start);
   ofstream file("bubbleS.txt", ios::app);
    file << "array size" << " " << "duration"<< endl;
    file << n << " " << duration.count() << endl;
    
    file.close();
    cout << "Output successfully written to bubbleS.txt" << endl;
    return 0;
}
