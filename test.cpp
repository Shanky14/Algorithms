#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
int linearsearch(int arr[], int size, int index, int key)
{
    if (index == size)
        return -1;
    if (arr[index] == key)
        return index;
    return linearsearch(arr, size, index + 1, key);
}
int main()
{
    int size;
    cout << "enter size of array: ";
    cin >> size;
    int arr[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
    int key = arr[size-1] ;
    auto start = high_resolution_clock::now();
    int result = linearsearch(arr, size, 0, key);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
        ofstream file("output.txt", ios::app);
    file << "array size" << " " << "duration"<< endl;
    if (result != -1)
    file << size << " " << duration.count() << endl;
    else
    file << size << " " << duration.count() << endl;
    file.close();
    cout << "Output successfully written to output.txt" << endl;
    return 0;
}