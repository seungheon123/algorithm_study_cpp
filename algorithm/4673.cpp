#include <iostream>
using namespace std;

bool arr[10001];
int solution(int n) {
    int sum = n;
    while (1) {
        if (n == 0) break;
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main() {
    for (int i = 1; i < 10001; i++) {
        int n = solution(i);
        if (n <= 10000) {
            arr[n] = true;
        }
    }
    for (int i = 1; i < 10001; i++) {
        if (!arr[i]) {
            cout << i << endl;
        }
    }
}