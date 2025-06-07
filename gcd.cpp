#include <iostream>   // For std::cin, std::cout, std::endl
#include <vector>     // For std::vector
#include <numeric>    // For std::gcd (C++17 standard library) - or use your custom gcd
#include <queue>      // For std::queue
#include <algorithm>  // For std::min, std::set (though not strictly needed if unique_a is built carefully)
#include <climits>    // For INT_MAX

// Function to compute gcd of two integers using Euclidean algorithm
// This is your provided gcd function, which is correct.
int custom_gcd(int a, int b) {
    while (b != 0) { // Loop continues as long as b is not zero
        int tmp = b;
        b = a % b; // b becomes the remainder of a / b
        a = tmp;   // a becomes the old b
    }
    return a; // When b is 0, a holds the GCD
}

void solve() {
    int n; 
    std::cin >> n; // Read the size of the array
    std::vector<int> a(n);
    
    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Special case: If there's only one element, 0 operations are needed.
    if (n == 1) {
        std::cout << 0 << "\n";
        return;
    }

    // Compute the overall GCD of the array
    int overall_gcd = a[0];
    for (int i = 1; i < n; i++) {
        overall_gcd = custom_gcd(overall_gcd, a[i]);
    }

    // Count how many elements are already equal to the overall_gcd
    int count_overall_gcd_present = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == overall_gcd) {
            count_overall_gcd_present++;
        }
    }

    // Case 1: If G is already present in the array
    if (count_overall_gcd_present > 0) {
        // We need 'n - (count of G)' operations to convert the rest.
        std::cout << n - count_overall_gcd_present << "\n";
    } 
    // Case 2: If G is not present in the array initially
    else {
        // We need to find the minimum operations (x) to generate G,
        // then add n-1 operations to convert the rest of the array using that G.
        
        const int MAX_A_VALUE = 5000; // Max possible value for an element

        // d[v] stores the minimum operations to make at least one element equal to 'v'
        std::vector<int> d(MAX_A_VALUE + 1, INT_MAX); 
        
        // BFS queue
        std::queue<int> q;
        
        // Get unique initial elements for efficient BFS transitions
        std::vector<int> unique_a;
        std::sort(a.begin(), a.end()); // Sort to easily find unique elements
        unique_a.reserve(n); // Reserve space to avoid reallocations
        if (n > 0) {
            unique_a.push_back(a[0]);
            for (int i = 1; i < n; ++i) {
                if (a[i] != a[i-1]) {
                    unique_a.push_back(a[i]);
                }
            }
        }
        
        // Initialize distances and queue with initial unique elements
        for (int val : unique_a) {
            d[val] = 0;
            q.push(val);
        }

        // Perform BFS
        while (!q.empty()) {
            int curr_val = q.front();
            q.pop();

            // Explore new values by taking GCD with any original unique element
            for (int orig_val : unique_a) {
                int new_val = custom_gcd(curr_val, orig_val);
                
                // If we found a shorter path to new_val
                if (d[curr_val] + 1 < d[new_val]) {
                    d[new_val] = d[curr_val] + 1;
                    q.push(new_val);
                }
            }
        }
        
        // 'ops_to_generate_G' is the minimum operations (x) to make one element equal to overall_gcd
        int ops_to_generate_G = d[overall_gcd];
        
        // Total operations = (ops to generate G) + (n-1 ops to convert rest)
        std::cout << ops_to_generate_G + (n - 1) << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; 
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}