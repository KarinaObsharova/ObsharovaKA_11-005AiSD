#include <iostream>


using namespace std;

void upSwap(int *a, int first, int second) {
    int temp = 0;
    temp = *(a + first);
    *(a + first) = *(a + second);
    *(a + second) = temp;
}

int sum(int *a, int size) {
    int arr[size];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    a = arr;
    int sumArr = 0;
    for (int i = 0; i < size; ++i) {
        sumArr = sumArr + *(a + i);
    }
    return sumArr;
}

void arr3(int *a, int *c, int *b) {
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 5; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < 5; ++i) {
        *(c + i) = *(a + i);
        *(c + 5 + i) = *(b + i);
    }
    for (int i = 0; i < 10; ++i) {
        cout << c[i] << " ";
    }

}


void sort(int *a, int size) {
    
    int arrSort[size];
    for (int i = 0; i < size; ++i) {
        cin >> arrSort[i];
    }
    a = arrSort;
    for (int out = size - 1; out > 0; --out) {
        for (int in = 0; in < out; in++) {
            if (*(a + in) > *(a + in + 1)) {
                upSwap(a, in, in + 1);
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        cout << arrSort[i] << " ";
    }
}


int main() {
    int *a1 = nullptr;
    cout << sum(a1, 5);

    int *a = new int[5];
    int *c = new int[5];
    int *b = new int[10];
    arr3(a, c, b);

    int *a3 = nullptr;
    sort(a3, 10);
    return 0;
}