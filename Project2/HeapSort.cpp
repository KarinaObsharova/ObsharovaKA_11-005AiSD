/*
#include <vector>
#include <iostream>
using namespace std;

namespace itis {
  void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
      largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
      largest = right;
    }

    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
  }

  void heapSort(vector<int> &arr, int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
      heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
    }
  }

}
int main(){
    vector<int> array = {10,5,7,8,9};

    itis:: heapSort(array, 5);

    for (int i = 0; i < 5; ++i) {
        cout << array[i];
    }
    return 0;
}
*/
