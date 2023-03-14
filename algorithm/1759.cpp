#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> pass;
vector<char> res;

bool check() {
	int vowel = 0;
	for (int i = 0; i < l; i++) {
		if (res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u') {
			vowel++;
		}
	}
	if (vowel >= 1 && l - vowel >= 2) return true;
	else return false;
}

void code(int k) {
	if (res.size() == l) {
		if (check()) {
			for (int i = 0; i < l; i++) {
				cout << res[i];
			}
			cout << '\n';
		}
	}
	for (int i = k; i < c; i++) {
		res.push_back(pass[i]);
		code(i + 1);
		res.pop_back();
	}
}

int main() {
	cin >> l >> c;
	char temp;
	for (int i = 0; i < c; i++) {
		cin >> temp;
		pass.push_back(temp);
	}
	sort(pass.begin(), pass.end());
	code(0);


}