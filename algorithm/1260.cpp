#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001];
void dfs(int);
void bfs(int);
int n, m, v;
int visited_dfs[1001];
int visited_bfs[1001];
int main() {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	dfs(v);
	cout << endl;
	bfs(v);
	return 0;
}

void dfs(int v) {
	cout << v << " ";
	visited_dfs[v] = 1;
	for (int i = 1; i < n + 1; i++) {
		if (visited_dfs[i] != 1 && arr[v][i] == 1) {
			dfs(i);
		}
	}
}

void bfs(int v) {
	queue<int> que;
	que.push(v);
	while (!que.empty()) {
		int a = que.front();
		visited_bfs[a] = 1;
		que.pop();
		for (int i = 1; i < n + 1; i++) {
			if (visited_bfs[i] != 1 && arr[a][i] == 1) {
				visited_bfs[i] = 1;
				que.push(i);
			}
		}
		cout << a << " ";
	}
}