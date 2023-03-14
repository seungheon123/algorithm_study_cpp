#include <iostream>
using namespace std;

int dp[12] = { 0 };

int main() {
	int t; cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}

	return 0;
}