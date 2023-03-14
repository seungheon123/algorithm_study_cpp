#include <iostream>
using namespace std;

int dp[501][501] = { 0 };

int main() {
	int n; cin >> n;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < i + 1; j++) {
			cin >> dp[i][j];
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < i + 1; j++) {
			if (j == 1) {
				dp[i][j] += dp[i - 1][j];
			}
			else if (j == i) {
				dp[i][j] += dp[i - 1][j - 1];
			}
			else {
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}
	int maxNum = 0;
	for (int i = 1; i < n + 1; i++) {
		maxNum = max(maxNum, dp[n][i]);
	}
	cout << maxNum;
	return 0;
}