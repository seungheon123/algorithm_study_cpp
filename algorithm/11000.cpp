#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> room;
priority_queue<int, vector<int>, greater<int>> pq;


int main() {
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		room.push_back(make_pair(a, b));
	}
	sort(room.begin(), room.end());
	pq.push(room[0].second);
	for (int i = 1; i < n; i++) {
		int StartTime = room[i].first;
		int EndTime = room[i].second;
		if (StartTime >= pq.top()) {
			pq.pop();
			pq.push(EndTime);
		}
		else {
			pq.push(EndTime);
		}
	}
	cout << pq.size() << endl;
}