#include <iostream>
#include <vector>

using namespace std;
namespace itis{
    int temp;

    void BubbleSort(vector<int> &arr, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}
int main(){
    vector<int> array = {11,5,7,8,9};

    itis:: BubbleSort(array, 5);

    for (int i = 0; i < 5; ++i) {
        cout << array[i];
    }
}

