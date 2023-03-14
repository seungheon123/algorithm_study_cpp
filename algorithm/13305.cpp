#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long road[100001];
    long long cost[100001];
    for (int i = 0; i < n - 1; i++) {
        cin >> road[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    long long min = cost[0];
    long long sum = min * road[0];
    for (int i = 1; i < n - 1; i++) {
        if (min <= cost[i]) {
            sum += min * road[i];
        }
        else if (min > cost[i]) {
            min = cost[i];
            sum += min * road[i];
        }
    }
    cout << sum << endl;
    return 0;
}