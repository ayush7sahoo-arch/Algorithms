#include <iostream>
using namespace std;

void solve() {
    long long n, s;
    cin >> n >> s;
    int potted_balls = 0;
    for (int i = 0; i < n; ++i) {
        long long dx, dy, x, y;
        cin >> dx >> dy >> x >> y;

        if (dx == dy) {
            if (x == y) {
                potted_balls++;
            }
        }

        else { 
            if (x + y == s) {
                potted_balls++;
            }
        }
    }
    cout << potted_balls <<endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}