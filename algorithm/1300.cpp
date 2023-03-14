#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long n, k;


int main() {
	cin >> n;
	cin >> k;

	unsigned long long left = 0;
	unsigned long long right = n * n;
	unsigned long long ans = 0;
	while (left <= right) {
		unsigned long long cnt = 0;
		unsigned long long mid = (left + right) / 2;
		for (int i = 1; i <= n; i++) {
			cnt += min(n, (unsigned long long)mid / i);
		}
		if (cnt >= k) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans;
}