#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<unsigned long long> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	unsigned long long temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	unsigned long long left = 0;
	unsigned long long right = v.back() * m;
	unsigned long long ans = 1000000000000000001;
	while (left <= right) {
		unsigned long long cnt = 0;
		unsigned long long mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			cnt += (mid / v[i]);
		}

		if (cnt >= m) {
			right = mid - 1;
			ans = min(mid, ans);
		}
		else {
			left = mid + 1;
		}
		//if (mid <= ans && cnt>=m) {
		//	ans = mid;
		//}
	}
	cout << ans << '\n';

	return 0;
}