#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    int time = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (time <= v[i].second) {
            time = v[i].first;
            cnt++;
        }
    }
    cout << cnt << endl;
}