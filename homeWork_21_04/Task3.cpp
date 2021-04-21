#include <iostream>

using namespace std;

int BinarySearch(int x, int right, int left) {
    int buf = right - left;
    int mid = left + (right - left) / 2;
    if (mid * mid == x)
        return mid;
    if(buf == 1) {
        if(abs(x- right*right) >abs(x-left*left) )
            return left;
        return right;
    }

    if (mid * mid > x)
        return BinarySearch(x, mid, left);

    if (mid * mid < x)
        return BinarySearch(x, right, mid + 1);




}





int main() {
    int x;
    cin >> x;
    int value = BinarySearch(x, x, 0);
    cout << value;
    return 0;
}