#include <iostream>
using namespace std;

int house[1001][3];


int main() {
	int n; cin >> n;
	int cost[3];
	for (int i = 1; i < n + 1; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		house[i][0] = min(house[i - 1][1] + cost[0], house[i - 1][2] + cost[0]);
		house[i][1] = min(house[i - 1][0] + cost[1], house[i - 1][2] + cost[1]);
		house[i][2] = min(house[i - 1][0] + cost[2], house[i - 1][1] + cost[2]);
	}
	cout << min(house[n][0], min(house[n][1], house[n][2]));
	return 0;
}