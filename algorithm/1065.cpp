#include <iostream>
using namespace std;

int main() {
	int n;
	int cnt = 99;
	cin >> n;
	if (n < 100) {
		cout << n << endl;
	}
	else {
		for (int i = 100; i <= n; i++) {
			int hund = i / 100;
			int ten = i / 10 % 10;
			int one = i % 10;
			if (hund - ten == ten - one) {
				cnt += 1;
			}
		}
		cout << cnt << endl;
	}
}