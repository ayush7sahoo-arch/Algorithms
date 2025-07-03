#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

const int MAX_M = 500001;
long long dp[MAX_M];
int spf[MAX_M]; // Smallest Prime Factor

void sieve() {
    // Standard sieve implementation to populate spf array
    for (int i = 1; i < MAX_M; i++) spf[i] = i;
    for (int i = 2; i * i < MAX_M; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j < MAX_M; j += i) {
                if (spf[j] == j) { // if j's spf is not set yet
                    spf[j] = i;
                }
            }
        }
    }
}

void precompute() {
    for (int i = 0; i < MAX_M; i++) dp[i] = -1;
    dp[1] = 1;
    sieve();

    for (int i = 2; i < MAX_M; i++) {
        // Path cost
        long long path_cost = -1;
        if (i - 2 >= 1 && dp[i - 2] != -1) {
            path_cost = 1 + dp[i - 2];
        }

        // Star cost using prime factorization
        long long star_cost = -1;
        long long sum_of_sub_costs = 0;
        bool possible = true;
        int temp = i;
        while (temp > 1) {
            int p = spf[temp];
            int s = p - 2;
            if (s <= 0 || dp[s] == -1) {
                possible = false;
                break;
            }
            sum_of_sub_costs += dp[s];
            temp /= p;
        }

        if (possible) {
            star_cost = 1 + sum_of_sub_costs;
        }

        // Combine
        if (path_cost != -1 && star_cost != -1) {
            dp[i] = min(path_cost, star_cost);
        } else if (path_cost != -1) {
            dp[i] = path_cost;
        } else {
            dp[i] = star_cost;
        }
    }
}

// In main function:
// call precompute() once
// then answer queries by looking up dp[m]
int main(){

    precompute();

    int t;
    scanf("%lld",&t);
    while(t--){
        int n;
        scanf("%lld",&n);
        printf("%lld\n",dp[n]);
    }

}