#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void ans(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[k] = i;
			ans(k + 1);
			visited[i] = false;

		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	ans(0);
	return 0;

}