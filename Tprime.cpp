#include <iostream>
#include <vector>
#include <string> // Added for std::string
#include <cmath>  // For sqrt and round

using namespace std;

bool isTprime(long long int n) {
    if (n < 4) { // Numbers 0, 1, 2, 3 are not T-primes. Smallest T-prime is 4 (2*2).
        return false;
    }

    long long int s = static_cast<long long int>(round(sqrt(static_cast<double>(n))));

    // Check if n is a perfect square.
    if (s * s != n) {
        return false; // If not a perfect square, it cannot be a T-prime.
    }


    if (s < 2) { // 0 and 1 are not prime.
        return false;
    }

    for (long long int i = 2; i * i <= s; i++) {
        if (s % i == 0) {
            return false; // s has a divisor other than 1 and itself, so it's not prime.
        }
    }

    return true;
}

int main() {
    // For faster I/O in C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;

    vector<string> ans(t); // Vector to store results ("YES" or "NO")

    for (int i = 0; i < t; i++) {
        long long int n_val; // The number to check (using a different name than in isTprime for clarity)
        cin >> n_val;
        if (isTprime(n_val)) {
            ans[i] = "YES";
        } else {
            ans[i] = "NO";
        }
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << "\n"; // Using "\n" for newline is generally faster than endl
    }

    return 0;
}