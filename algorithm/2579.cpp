#include <iostream>
using namespace std;

int stairs[301];
int dp[301];

int main() {
	int t; cin >> t;
	for (int i = 1; i < t + 1; i++) {
		cin >> stairs[i];
	}
	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
	for (int i = 4; i < t + 1; i++) {
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}
	cout << dp[t];

	return 0;
}