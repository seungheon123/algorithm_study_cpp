#include <iostream>
using namespace std;
long long ans = 0;
long long arr[10001];



int main() {
	int k, n, m = 0;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		arr[i] = a;
		if (a > m) { m = a; }
	}
	long long low = 1;
	long long high = m;
	while (high >= low) {
		long long cnt = 0;
		long long mid = (high + low) / 2;
		for (int i = 0; i < k; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt >= n) {
			low = mid + 1;
			ans = max(ans, mid);
		}
		else {
			high = mid - 1;
		}
	}
	cout << ans << endl;

}