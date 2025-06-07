#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <unordered_map> // Changed from <map> to <unordered_map>
#include <set>
#include <tuple>     // Required for std::tuple
#include <functional> // Required for std::hash

using namespace std;

// Custom hash function for std::tuple<int, int, int, int>
// This is necessary for using std::tuple as a key in std::unordered_map.
namespace std {
    template<> struct hash<tuple<int, int, int, int>> {
        size_t operator()(const tuple<int, int, int, int>& t) const {
            // A simple combination of hashes for the tuple elements.
            // More sophisticated hash combining techniques exist, but this is often sufficient.
            size_t h1 = hash<int>()(get<0>(t)); // Hash for mask
            size_t h2 = hash<int>()(get<1>(t)); // Hash for sorted_w
            size_t h3 = hash<int>()(get<2>(t)); // Hash for sorted_l
            size_t h4 = hash<int>()(get<3>(t)); // Hash for sorted_h

            // Combine hashes using XOR and bit shifts to reduce collisions.
            return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (h4 << 3);
        }
    };
}

// Fibonacci numbers: f_1=1, f_2=2, f_i=f_{i-1}+f_{i-2} for i>2
// f_1=1, f_2=2, f_3=3, f_4=5, f_5=8, f_6=13, f_7=21, f_8=34, f_9=55, f_10=89
vector<int> fib_vals(10); // fib_vals[0] stores f_1, ..., fib_vals[9] stores f_10

// Memoization table: (mask, w, l, h) -> bool
// Using std::unordered_map for faster average-case lookups and insertions.
// The dimensions (w, l, h) are sorted in the key to normalize permutations.
unordered_map<tuple<int, int, int, int>, bool> memo;

int N_cubes; // Number of cubes for the current test case (n from input)

// Function to precompute the first 10 Fibonacci numbers based on the problem's definition.
void precompute_fib() {
    fib_vals[0] = 1; // f_1
    fib_vals[1] = 2; // f_2
    for (int i = 2; i < 10; ++i) {
        fib_vals[i] = fib_vals[i - 1] + fib_vals[i - 2];
    }
}

// Recursive function to check if cubes in 'mask' can fit into box (w, l, h).
// This function implements a common heuristic for 3D packing problems with small N:
// 1. Always try to place the largest remaining cube.
// 2. After placing it, recursively check if the remaining cubes can fit into one of the
//    three rectangular sub-spaces created by cutting the original box.
bool solve(int mask, int w, int l, int h) {
    // Base case: If the mask is 0, it means all cubes have been successfully placed.
    if (mask == 0) {
        return true;
    }

    // Normalize dimensions for the memoization key: always sort (w, l, h)
    // This ensures that different permutations of the same dimensions (e.g., (10,5,2) vs (5,10,2))
    // map to the same memoization state, reducing redundant computations.
    vector<int> current_dims = {w, l, h};
    sort(current_dims.begin(), current_dims.end());
    tuple<int, int, int, int> state = {mask, current_dims[0], current_dims[1], current_dims[2]};

    // Memoization check: If this state has already been computed, return the stored result.
    if (memo.count(state)) {
        return memo[state];
    }

    // Find the largest available cube in the current mask.
    // Iterating from N_cubes-1 down to 0 ensures we find the largest Fibonacci number (f_N, then f_{N-1}, etc.).
    int first_cube_idx = -1; // Index in fib_vals (0 to N_cubes-1)
    for (int i = N_cubes - 1; i >= 0; --i) {
        if ((mask >> i) & 1) { // Check if the i-th cube is present in the mask
            first_cube_idx = i;
            break;
        }
    }
    
    // If no cube is found (shouldn't happen if mask > 0 and N_cubes is valid), return false.
    if (first_cube_idx == -1) {
        return false; 
    }

    int S = fib_vals[first_cube_idx]; // Side length of the cube to place
    int next_mask = mask ^ (1 << first_cube_idx); // Mask after removing the current cube

    bool possible = false;

    // Try all 6 permutations of the current box dimensions (w, l, h).
    // This is because the box can be oriented in different ways relative to the cube.
    // We sort 'p' initially to ensure that 'next_permutation' generates unique permutations.
    vector<int> p = {w, l, h}; 
    sort(p.begin(), p.end()); 

    do {
        int W_perm = p[0];
        int L_perm = p[1];
        int H_perm = p[2];

        // Check if the chosen cube (S x S x S) fits into the current permutation of box dimensions.
        if (S > W_perm || S > L_perm || S > H_perm) {
            continue; // Cube does not fit in this orientation, try next permutation.
        }

        // If the cube fits, we try to place it and then recursively pack the remaining cubes.
        // The heuristic involves checking if the remaining cubes can fit into *one* of the
        // three rectangular sub-spaces created by cutting the box along one axis.

        // Option 1: Cut along W_perm (remaining width)
        // The cube S is placed in a S x L_perm x H_perm section. The remaining space is (W_perm - S) x L_perm x H_perm.
        if (solve(next_mask, W_perm - S, L_perm, H_perm)) {
            possible = true;
            break; // Found a solution, no need to check further permutations or cuts.
        }
        
        // Option 2: Cut along L_perm (remaining length)
        // The cube S is placed in a W_perm x S x H_perm section. The remaining space is W_perm x (L_perm - S) x H_perm.
        if (solve(next_mask, W_perm, L_perm - S, H_perm)) {
            possible = true;
            break; // Found a solution.
        }
        
        // Option 3: Cut along H_perm (remaining height)
        // The cube S is placed in a W_perm x L_perm x S section. The remaining space is W_perm x L_perm x (H_perm - S).
        if (solve(next_mask, W_perm, L_perm, H_perm - S)) {
            possible = true;
            break; // Found a solution.
        }

    } while (next_permutation(p.begin(), p.end())); // Generate next permutation of dimensions

    // Store the result in the memoization table before returning.
    return memo[state] = possible;
}

// Function to handle each test case.
string solve_test_case() {
    int m; // Number of empty boxes
    cin >> N_cubes >> m;

    string result = ""; // String to store '1' or '0' for each box

    for (int i = 0; i < m; ++i) {
        int w, l, h; // Dimensions of the current box
        cin >> w >> l >> h;

        memo.clear(); // Clear the memoization table for each new box.
                      // This is crucial because box dimensions (w,l,h) are unique per query,
                      // and the 'solve' function is specific to these dimensions.

        // Call the recursive solve function with all N_cubes (represented by (1 << N_cubes) - 1 mask)
        // and the current box dimensions.
        if (solve((1 << N_cubes) - 1, w, l, h)) {
            result += '1'; // All cubes can fit
        } else {
            result += '0'; // All cubes cannot fit
        }
    }
    return result; // Output the result string for the current test case
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_fib(); // Precompute Fibonacci numbers once at the start.

    int t; // Number of test cases
    cin >> t;
    vector<string> results(t); // Store results for all test cases
    for(int i=0;i<t;i++){
        results.push_back(solve_test_case()); // Process each test case.
    }
    for(const auto& res : results) {
        cout << res << endl; // Output results for all test cases
    }

    return 0;
}
