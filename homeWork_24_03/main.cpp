#include <iostream>
using namespace std;

struct MaxHeap{
    int *array;
    int size = 0;
    int maxSize = 0;

    int Patent(int i){
        return (i - 1) / 2;
    }
    int LeftChild(int i){
        return 2 * i + 1;
    }
    int RightChild(int i){
        return  2 * i + 2;
    }

    void ShiftUp(int i){
        while (i >= 1 && array[i] > array[Patent(i)]){
            int temp = array[i];
            array[i] = array[Patent(i)];
            array[Patent(i)] = temp;
            i = Patent(i);
            ShiftUp(i);
        }
    }
    void ShiftDown(int i){
        int maxIndex = i;
        if(array[LeftChild(i)] > array[maxIndex] && LeftChild(i) < size - 1){
            maxIndex = LeftChild(i);
        }
        if(array[RightChild(i)] > array[maxIndex] && RightChild(i) < size -1){
            maxIndex = RightChild(i);
        }
        if(maxIndex != i){
            int temp = array[i];
            array[i] = array[maxIndex];
            array[maxIndex] = temp;
            ShiftDown(maxIndex);
        }
    }
    int Insert(int p) {
        if (size < maxSize) {
            size++;
        } else {
            maxSize = maxSize * 2 + 1;
            ExpansionArray(maxSize);
            size++;
        }
        array[size - 1] = p;
        ShiftUp(size - 1);
    }
    int ExtractMax(){
        int result = array[0];
        array[0] = array[size-1];
        size--;
        ShiftDown(0);
        return result;
    }
    void ExpansionArray(int maxSize){
        int *arr = new int[maxSize];
        if(maxSize > 1) {
            for (int i = 0; i < size; ++i) {
                arr[i] = array[i];
            }
            delete[] array;
        }
            array = arr;
    }
};

int * HeapSort(int * array, int size) {
    MaxHeap * maxHeap = new MaxHeap;
    int * arr = new int[size];
    for (int i = 0; i < size; ++i) {
        maxHeap->Insert(array[i]);
    }
    for (int i = 0; i < size; ++i) {
        arr[i] = maxHeap->ExtractMax();
    }
    delete[] array;
    return arr;
}

int main() {
    int size = 10;
   int *arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    arr = HeapSort(arr, size);
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
