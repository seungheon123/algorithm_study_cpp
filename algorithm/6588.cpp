#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check[1000001] = { 0 };
vector<int> prime;

int n;

void checkP() {
	for (int i = 2; i * i <= 1000000; i++) {
		if (check[i] == 0) {
			for (int j = i * i; j <= 1000000; j = j + i) {
				check[j] = 1;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	checkP();
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 2; i <= n; i++) {
			if (check[i] == 0) {
				int k = n - i;
				if (check[k] == 0) {
					cout << n << " = " << i << " + " << k << "\n";
					break;
				}
			}
		}
	}

	return 0;
}
