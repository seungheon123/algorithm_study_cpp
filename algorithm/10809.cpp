#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int ans[26];
    for (int i = 0; i < 26; i++) {
        ans[i] = -1;
    }
    for (int i = 0; i < str.size(); i++) {
        if (ans[str[i] - 'a'] == -1) {
            ans[str[i] - 'a'] = i;
        }
    }
    for (int i = 0; i < 26; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}