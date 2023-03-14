#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> vec;


int main() {
	cin >> n >> c;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	int left = 0;
	int right = vec[vec.size() - 1] - vec[0];
	int ans = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int set_num = 1;
		int set_before = vec[0];
		for (int i = 1; i < vec.size(); i++) {
			if (vec[i] - set_before >= mid) {
				set_num++;
				set_before = vec[i];
			}
		}
		if (set_num < c) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
		if (mid > ans && set_num >= c) {
			ans = mid;
		}
	}

	cout << ans;
}