#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long x, y, ans;
		cin >> x >> y;
		if (x > y) {
			break;
		}
		long long k = 0;
		while (y - x > k * k) {
			k++;
		}
		if ((y - x) > ((k * k) + ((k - 1) * (k - 1))) / 2) {
			ans = (k * 2) - 1;
		}
		else if ((y - x) <= ((k * k) + ((k - 1) * (k - 1))) / 2) {
			ans = (k - 1) * 2;
		}
		else {
			ans = k + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}