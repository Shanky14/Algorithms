#include <iostream>
#include <vector>
using namespace std;
int duplicate(int arr[],int size)
{
    int dup = -1;
    int n = size / 2;

    for (int i = 0; i < n; i++)
    {
        int temp = arr[n - 1];
        for (int j = 0; j < n - i; j++)
        {
            if (temp == arr[j])
            {
                dup = temp;
                break;
            }
        }
    }return dup;
}
int main()
{
    int arr[] ={1,2,3,1,3,4,4,1,3};
    int size =sizeof(arr)/sizeof(arr[0]);
    cout<<"Duplicate : "<<duplicate(arr,size)<<endl;
    return 0;
}