#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int t;
    std::cin >> t;
    std::vector<long long> ans(t);
    
    for (int i = 0; i < t; i++) {
        long long n, k, x;
        std::cin >> n >> k >> x;
        
        std::vector<long long> arr(n);
        for (int j = 0; j < n; j++) {
            std::cin >> arr[j];
        }

        long long sum = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[j];
        }

        // Check for division by zero
        if (sum == 0) {
            ans[i] = (x == 0) ? k * n : 0; // If sum is zero, check if x is also zero
            continue;
        }

        // Calculate the number of full rounds needed
        long long round = (x + sum - 1) / sum; // This is equivalent to ceil(x / sum)
        long long count = 0;
        long long tot = round * sum;

        // Count how many elements can be used
        for (int j = 0; j < n && tot >= x; j++) {
            count++;
            tot -= arr[j];
        }

        // Check if the number of rounds exceeds k or if k * sum is less than x
        if (round > k || k * sum < x) {
            ans[i] = 0;
        } else {
            ans[i] = (k - round) * n + count;
        }
    }

    for (int i = 0; i < t; i++) {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}
