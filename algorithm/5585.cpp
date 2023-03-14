#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int r = 1000 - n;
    int cnt = 0;
    while (1) {
        if (r == 0)
            break;
        if (r >= 500) {
            r -= 500;
            cnt++;
        }
        else if (r < 500 && r >= 100) {
            cnt += r / 100;
            r %= 100;
        }
        else if (r < 100 && r >= 50) {
            r -= 50;
            cnt++;
        }
        else if (r < 50 && r >= 10) {
            cnt += r / 10;
            r %= 10;
        }
        else if (r < 10 && r >= 5) {
            r -= 5;
            cnt++;
        }
        else if (r < 5 && r >= 1) {
            cnt += r;
            break;
        }
    }
    cout << cnt << endl;
}