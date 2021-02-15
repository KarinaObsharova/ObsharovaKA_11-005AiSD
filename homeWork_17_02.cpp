#include <iostream>
#include "math.h"

using namespace std;

int sum() {
    int n = 0;
    cin >> n;
    int a;
    int f;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        f += a;
    }
    return f;
}
void sqrt1(){
    int a; int b; int c;
    cin >> a >> b >> c;
    int d = b * b - 4 * a * c;
    if ( d > 0){
        double x1 = (double) (-b + sqrt(d))/ 2*a;
        double x2 = (double) (-b - sqrt(d))/ 2*a;
        cout << x1 << " " << x2;
    }
    if ( d == 0){
        double x1 = (double) (-b/ 2*a);
        cout << x1;
    }
    if ( d < 0){
        cout << "Нет корней.";
    }
}
void log(){
    int x;
    cin >> x;
    int p = 2;
    int f = 0;
    while (p < x){
        f++;
        p *= 2;
    }
    cout << f;
}
int power(int x, unsigned p){
    int y = 1;
    for (int i = 0; i < p; ++i) {
        y = y * x;
    }
   return y;
}

int main() {
    cout << sum();
    sqrt1();
    log();
    int x;
    unsigned p;
    cin >> x; cin >> p;
    cout << power(x, p);
    return 0;
}

