#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int cnt = 0;
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++) {
        while (k - arr[i] >= 0) {
            k -= arr[i];
            cnt++;
        }
    }
    cout << cnt << endl;
}
