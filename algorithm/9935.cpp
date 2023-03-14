#include <iostream>
#include <stack>
using namespace std;

int main() {
	string a;
	string b;
	cin >> a;
	cin >> b;
	int len_a = a.length();
	int len_b = b.length();
	string ans;
	for (int i = 0; i < len_a; i++) {
		ans += a[i];
		if (ans.length() >= len_b) {
			bool flag = true;
			for (int j = 0; j < len_b; j++) {
				if (ans[ans.length() - len_b + j] != b[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				ans.erase(ans.end() - len_b, ans.end());
			}
		}
	}
	if (ans.empty()) {
		cout << "FRULA" << '\n';
	}
	else {
		cout << ans;
	}

}