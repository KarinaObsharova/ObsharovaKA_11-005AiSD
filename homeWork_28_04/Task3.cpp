#include <iostream>

using namespace  std;
int count( int n, int m){
    int **arr = new int*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[n];
        for (int j = 0; j < m; ++j) {
            if(i == 0 || j == 0){
                arr[i][j] = 1;
            } else {
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }

        }
    }
    return arr[n-1][m-1];
}

int main() {
    int n, m;
    cin >> n >> m;
 cout << count(n, m);
    return 0;
}

