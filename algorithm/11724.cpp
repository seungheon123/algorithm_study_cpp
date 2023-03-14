#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v[1001];
int visited[1001];

void dfs(int index) {
	visited[index] = 1;
	for (int i = 0; i < v[index].size(); i++) {
		if (visited[v[index][i]] == 1) continue;
		dfs(v[index][i]);
	}
}

int main() {
	cin >> n >> m;
	int a, b;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i < n + 1; i++) {
		if (visited[i]) continue;
		dfs(i);
		cnt++;
	}

	cout << cnt;
	return 0;
}