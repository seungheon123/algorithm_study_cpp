#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        int cnt = 0;
        int avg = 0;
        cin >> a;
        int arr[a];
        for (int i = 0; i < a; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < a; i++) {
            avg += arr[i];
        }
        avg /= a;
        for (int i = 0; i < a; i++) {
            if (arr[i] > avg) cnt++;
        }
        double result = double(cnt) / a * 100;
        cout << fixed;
        cout.precision(3);
        cout << result << "%" << endl;
    }

}