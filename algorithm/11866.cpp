#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> que;
	queue<int> ans;
	for (int i = 1; i < n + 1; i++) {
		que.push(i);
	}
	int cnt = k - 1;
	while (!que.empty()) {
		if (cnt == 0) {
			ans.push(que.front());
			que.pop();
			cnt = k - 1;
		}
		else {
			que.push(que.front());
			que.pop();
			cnt--;
		}
	}
	cout << "<";
	for (int i = 0; i < n; i++) {
		cout << ans.front();
		if (ans.size() != 1) cout << ", ";
		ans.pop();
	}
	cout << ">";
}