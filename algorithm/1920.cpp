#include <iostream>
#include<algorithm>
using namespace std;


int arr[1000000];
int n, m;

void binary_search(int target, int arr[]) {
	int start = 0;
	int end = n - 1;
	int mid;
	while (end >= start) {
		mid = (start + end) / 2;
		if (arr[mid] == target) {
			cout << 1 << '\n';
			return;
		}
		else if (arr[mid] > target) {
			end = mid -= 1;
		}
		else {
			start = mid += 1;
		}
	}
	cout << 0 << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		binary_search(k, arr);
	}
	return 0;
}
