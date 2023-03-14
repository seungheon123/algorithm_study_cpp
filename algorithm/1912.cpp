#include <iostream>
using namespace std;

int arr[100001] = { 0 };
int dp[100001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	for (int i = 2; i < n + 1; i++) {
		dp[i] = max(dp[i - 1] + arr[i], max(arr[i - 1] + arr[i], arr[i]));
	}
	int ans = -1000;
	for (int i = 1; i < n + 1; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}