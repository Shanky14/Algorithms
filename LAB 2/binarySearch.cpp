#include<iostream>
#include<vector>
#include<chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
int binaryS(vector<int> &a,int st,int end,int target)
{
 int mid=st+(end-st)/2;
 while(st<end){
    if(a[mid]==target) return mid;
    else if(a[mid]<target) return binaryS(a,mid+1,end,target);
    else if(a[mid]>target)return binaryS(a,st,mid-1,target);
    else return -1;
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
  sort(a.begin(),a.end());
  int target = a[n-1];
  auto start = high_resolution_clock::now();
  int index = binaryS(a,0,a.size()-1,target);
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(end - start);
  cout<<"Index found at :"<<index<<endl;
  cout << "Time taken for searching : " << duration.count() << " ns\n";
    return 0;
}