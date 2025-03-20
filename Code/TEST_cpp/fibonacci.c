#include <iostream>
using namespace std;

void Fibonacci(int n) {
    int a = 0, b = 1, c = 0;
    for (int i = 0; i < n; i++) {
        c = a;
        a = b;
        b = c + b;
    }
    cout << a;
}

int main() {
    Fibonacci(1000000);
    return 0;
}
