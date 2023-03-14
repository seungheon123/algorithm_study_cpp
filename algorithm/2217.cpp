#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, (n - i) * arr[i]);
    }
    cout << ans << endl;
}