#include <stdio.h>   // For scanf, printf
#include <stdlib.h>  // For malloc, free
#include <string.h>  // For strlen (used for path string length, if needed for debugging)
#include <math.h>    // Not strictly needed for min_ll, but useful for other math functions

// Structure to hold counts of factors 2 and 5
struct Pair {
    long long a; // Count of factor 2s
    long long b; // Count of factor 5s
};

// Structure for DP table nodes, storing path information
struct Node {
    struct Pair p; // Accumulated factors (2s and 5s) to reach this cell
    char c;        // Direction taken to reach this cell ('D' for Down, 'R' for Right)
};

// Custom min function for long long integers
long long min_ll(long long a, long long b) {
    return (a < b ? a : b);
}

// Calculates the "power" (minimum of factor 2s and 5s) for a given Pair
long long get_power(struct Pair p) {
    return min_ll(p.a, p.b);
}

// Adds two Pair structures element-wise
struct Pair add_pairs(struct Pair p1, struct Pair p2) {
    struct Pair result;
    result.a = p1.a + p2.a;
    result.b = p1.b + p2.b;
    return result;
}

// Extracts counts of factors 2 and 5 from a number.
// Handles the special case for '0' in the input grid.
struct Pair extractPower(long long n) {
    // For n=1, there are no factors of 2 or 5 that contribute to trailing zeros.
    if (n == 1) {
        return (struct Pair){0, 0};
    }

    long long temp = n;
    long long c2 = 0, c5 = 0;

    // Count factors of 2
    while (temp > 0 && temp % 2 == 0) {
        c2++;
        temp /= 2;
    }
    
    // Reset temp for factor 5 calculation
    temp = n; 
    
    // Count factors of 5
    while (temp > 0 && temp % 5 == 0) {
        c5++;
        temp /= 5;
    }
    return (struct Pair){c2, c5};
}

void solve() {
    int n;
    scanf("%d", &n);

    long long **a;       // Input matrix
    struct Node **dp;    // Dynamic Programming table

    // Allocate memory for the input matrix (n rows)
    a = (long long**)malloc(n * sizeof(long long*));
    for (int i = 0; i < n; i++) {
        // Allocate memory for each row (n columns)
        a[i] = (long long*)malloc(n * sizeof(long long));
    }

    // Allocate memory for the DP table (n rows)
    dp = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        // Allocate memory for each row of Node structs (n columns)
        dp[i] = (struct Node*)malloc(n * sizeof(struct Node));
    }

    // Flags for handling zero in the input matrix
    int has_zero = 0;
    int zero_r = -1, zero_c = -1;

    // Read input and detect the first occurrence of 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
            if (a[i][j] == 0) {
                // If a zero is found, mark its presence and coordinates.
                // We only need the first one found as any path through a zero results in 1 trailing zero.
                has_zero = 1;
                zero_r = i;
                zero_c = j;
            }
        }
    }

    // Fill the DP table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            struct Pair currentPower;
            if (a[i][j] == 0) {
                // If the current cell contains 0, it contributes one 2 and one 5 factor.
                // This makes its 'power' 1, ensuring if a path goes through 0, the product is 0, which has 1 trailing zero.
                currentPower = (struct Pair){1, 1}; 
            } else {
                currentPower = extractPower(a[i][j]);
            }

            if (i == 0 && j == 0) {
                // Base case: starting cell
                dp[i][j].p = currentPower;
                // 'S' for start, not used in path reconstruction, just a placeholder.
                dp[i][j].c = 'S'; 
            } else if (i == 0) { 
                // First row: can only come from the left
                dp[i][j].p = add_pairs(dp[i][j - 1].p, currentPower);
                dp[i][j].c = 'R'; // Came from Right (moved Left to Right)
            } else if (j == 0) { 
                // First column: can only come from above
                dp[i][j].p = add_pairs(dp[i - 1][j].p, currentPower);
                dp[i][j].c = 'D'; // Came from Down (moved Up to Down)
            } else { 
                // General case: choose path from up or left that minimizes trailing zeros.
                struct Pair up_path_power = add_pairs(dp[i - 1][j].p, currentPower);
                struct Pair left_path_power = add_pairs(dp[i][j - 1].p, currentPower);

                // Compare based on the minimum of factors 2 and 5 for each potential path
                long long up_val = get_power(up_path_power);
                long long left_val = get_power(left_path_power);
                
                if(up_path_power.b == left_path_power.b){
                if (up_val < left_val) {
                    dp[i][j].p = up_path_power;
                    dp[i][j].c = 'D';
                } else { // If left_val is less or equal, choose left (or up by some tie-break)
                    dp[i][j].p = left_path_power;
                    dp[i][j].c = 'R';
                }
            }else{
                if (up_path_power.b < left_path_power.b) {
                    dp[i][j].p = up_path_power;
                    dp[i][j].c = 'D'; // Preferred to come from Down (means we went D to here)
                } else { 
                    dp[i][j].p = left_path_power;
                    dp[i][j].c = 'R'; // Preferred to come from Right (means we went R to here)
                }
            }
        }
        }
    }

    // Get the minimum number of trailing zeros from the DP result at the destination
    long long final_min_zeros = get_power(dp[n-1][n-1].p);
    
    // Allocate memory for the path string. Max length is 2*N-2 for D and R moves. Add 1 for null terminator.
    char *path_str = (char*)malloc((2 * n) * sizeof(char)); 
    int path_idx = 0;

    // Special handling if a zero was found in the input grid AND
    // the DP calculated result is worse (more than 1 trailing zero).
    if (has_zero && final_min_zeros > 1) {
        printf("1\n"); // Output 1 as the minimum trailing zeros
        // Construct the path: go down to zero_r, then right to zero_c,
        // then down to n-1, then right to n-1.
        for (int k = 0; k < zero_r; k++) path_str[path_idx++] = 'D';
        for (int k = 0; k < zero_c; k++) path_str[path_idx++] = 'R';
        for (int k = zero_r; k < n - 1; k++) path_str[path_idx++] = 'D';
        for (int k = zero_c; k < n - 1; k++) path_str[path_idx++] = 'R';
        path_str[path_idx] = '\0'; // Null-terminate the string
        printf("%s\n", path_str);
    } else {
        // Otherwise, use the result from the DP table
        printf("%lld\n", final_min_zeros);
        
        int i = n - 1, j = n - 1;
        // Backtrack from (n-1, n-1) to (0,0) to reconstruct the path
        while (i != 0 || j != 0) {
            // The 'c' in dp[i][j] indicates the direction taken to *arrive* at (i,j)
            // So, if 'R', we came from (i, j-1), meaning our move was 'R'
            // If 'D', we came from (i-1, j), meaning our move was 'D'
            if (dp[i][j].c == 'R') {
                path_str[path_idx++] = 'R';
                j--; // Move left to the previous cell
            } else { // dp[i][j].c == 'D'
                path_str[path_idx++] = 'D';
                i--; // Move up to the previous cell
            }
        }
        
        // The path is built in reverse order, so reverse it before printing
        for (int k = 0; k < path_idx / 2; k++) {
            char temp = path_str[k];
            path_str[k] = path_str[path_idx - 1 - k];
            path_str[path_idx - 1 - k] = temp;
        }
        path_str[path_idx] = '\0'; // Null-terminate the string
        printf("%s\n", path_str);
    }

    // Free dynamically allocated memory to prevent leaks
    for (int i = 0; i < n; i++) {
        free(a[i]);
        free(dp[i]);
    }
    free(a);
    free(dp);
    free(path_str);
}

int main() {
    // The original Java code's main function called solve() once,
    // so this C main also calls solve() once.
    // If multiple test cases were needed, a loop would be added here.
    solve();
    return 0;
}