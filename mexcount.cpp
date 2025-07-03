#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n;
    std::cin >> n;

    // The permutation we are building.
    // A value of 0 means the position is unassigned.
    std::vector<int> p(n + 1, 0);

    // p[1] must be 1.
    p[1] = 1;

    // Greedily pair i with 2*i.
    for (int i = 2; i <= n; ++i) {
        // If i has already been assigned a value, skip it.
        if (p[i] != 0) {
            continue;
        }

        long long current = i;
        // Try to form a pair (current, 2*current)
        if (current * 2 <= n) {
            long long partner = current * 2;
            
            // Link the chain as long as possible
            while(partner <= n) {
                // If the partner position is already filled, we can't continue the chain
                if (p[partner] != 0) break;

                p[current] = partner;
                current = partner;
                partner = current * 2;
            }
            // Close the cycle
            p[current] = i;
        }
    }
    
    // Any number that wasn't part of a pair/cycle becomes a fixed point.
    for (int i = 1; i <= n; ++i) {
        if (p[i] == 0) {
            p[i] = i;
        }
    }

    // Print the resulting permutation.
    for (int i = 1; i <= n; ++i) {
        std::cout << p[i] << (i == n ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}