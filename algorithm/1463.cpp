#include <iostream>
using namespace std;

void solution(int n);

int dp[1000001] = { 0 };


int main() {
	int n;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	cin >> n;
	for (int i = 5; i < n + 1; i++) {
		solution(i);
	}
	cout << dp[n] << endl;
	return 0;
}

void solution(int n) {
	if (n % 3 != 0 && n % 2 != 0) {
		dp[n] = dp[n - 1] + 1;
	}
	else if (n % 2 == 0 && n % 3 == 0) {
		dp[n] = min(1 + dp[n / 2], 1 + dp[n / 3]);
	}
	else if (n % 2 == 0) {
		dp[n] = min(dp[n / 2] + 1, dp[n - 1] + 1);
	}
	else {
		dp[n] = min(dp[n / 3] + 1, dp[n - 1] + 1);
	}
}