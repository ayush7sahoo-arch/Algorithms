#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> mine(n);
        for (int i = 0; i < n; i++) {
            cin >> mine[i];
        }

        int max_gold = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mine[i][j] == '.') {
                    int gold_collected = 0;

                    for (int x = max(0, i - k); x <= min(n - 1, i + k); x++) {
                        for (int y = max(0, j - k); y <= min(m - 1, j + k); y++) {

                            if (x == max(0, i - k) || x == min(n - 1, i + k) || 
                                y == max(0, j - k) || y == min(m - 1, j + k)) {
                                if (mine[x][y] == 'g') {
                                    gold_collected++;
                                }
                            }
                        }
                    }

                    max_gold = max(max_gold, gold_collected);
                }
            }
        }

        cout << max_gold<<"*" << endl;
    }
    return 0;
}
