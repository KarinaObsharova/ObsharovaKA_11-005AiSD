/*
#include <iostream>

using namespace std;
bool BinarySearch(int *array, int x, int left, int right) {
    int mid = (right - left) / 2;

    if (array[mid] == x) {
        return true;
    }
    if(right - left == 1) {
        return false;
    }

    if (array[mid] < x)
        return BinarySearch(array, x, mid, right);
    else
        return BinarySearch(array, x, left, mid);



}
bool search(int arr[3][3], int num)
{
    int right = 3-1;
    int left = 0;
    int middle = 3/2;
    int row1 = -1;
    int row2 = -1;
    while (true)
    {
        if(num > arr[middle][3 - 1])
        {
            left = middle;
            middle -= abs(right - left)/2;
        }
        if(num < arr[middle][3 - 1])
        {
            right = middle;
            middle -= abs(right - left)/2;
        }
        if(num == arr[middle][3 - 1])
            return true;
        if(right - left == 1)
        {
            row1  = right;
        row2 = left;
        }

        if(row1 == -1 && row2 == -1)
            return false;
        return BinarySearch(arr[row1], num, 0, 2 ) ||BinarySearch(arr[row2], num, 0, 2 )  ;

    }
}

int main() {
    int matrix[3][3] = {{1,2,3},
                        {4,5,6},
                        {7, 56, 90}};
    int x;
    cin >> x;
     bool iddmkd = search(matrix, x);
     cout << iddmkd;
    return 0;
}*/
