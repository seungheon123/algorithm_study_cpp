#include <iostream>
#include <vector>
using namespace std;

int map[101][101];
int visit[101];

int n;
int ans = 0;

void dfs(int a) {
	visit[a] = 1;
	for (int i = 1; i < n + 1; i++) {
		if (!visit[i] && map[a][i] == 1) {
			ans++;
			dfs(i);
		}
	}

}


int main() {
	int m;
	int a, b;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	dfs(1);
	cout << ans;
}