#include<iostream>
#include<vector>
using namespace std;
int missingNum(vector<int> &nums)
{
    int x=0;
    int n=nums.size();
    for (int i = 0; i <= n; i++)
    {
        x^=i;
    }
    
    for(int num:nums)
    {
        x^=num;
    }
    return x;
}
int main()
{
    vector<int> nums={0,1,2,4};
    cout<<missingNum(nums);
    return 0;
}
