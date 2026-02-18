#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int partitionFunc(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortIterative(vector<int> &arr) {
    int n = arr.size();

    stack<int> st;

    // push initial range
    st.push(0);
    st.push(n - 1);

    while (!st.empty()) {
        int high = st.top(); st.pop();
        int low  = st.top(); st.pop();

        int p = partitionFunc(arr, low, high);

        // left side
        if (p - 1 > low) {
            st.push(low);
            st.push(p - 1);
        }

        // right side
        if (p + 1 < high) {
            st.push(p + 1);
            st.push(high);
        }
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    quickSortIterative(arr);

    for (int x : arr)
        cout << x << " ";
}