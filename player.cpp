#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> player(n), dealer(n);
        for (int i = 0; i < n; i++) {
            cin >> player[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> dealer[i];
        }

        sort(player.begin(), player.end());
        sort(dealer.begin(), dealer.end());

        int points = 0;
        int j = 0;

        // Calculate initial points without swaps
        for (int i = 0; i < n; i++) {
            if (player[i] > dealer[j]) {
                points++;
                j++;
            }
        }

        // Now check for the possibility of a swap
        int max_points = points;

        // Try to find the best swap
        for (int i = 0; i < n; i++) {
            // Check if we can swap player[i] with a card that can win against dealer[j]
            if (player[i] <= dealer[j]) {
                // Find a card in the player's hand that can win against dealer[j]
                for (int k = 0; k < n; k++) {
                    if (player[k] > dealer[j]) {
                        // Simulate the swap
                        int new_points = points - (player[i] > dealer[j] ? 1 : 0) + 1;
                        max_points = max(max_points, new_points);
                        break; // No need to check further for this dealer card
                    }
                }
            }
        }

        cout << max_points << endl;
    }
    return 0;
}
