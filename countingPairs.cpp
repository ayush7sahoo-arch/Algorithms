#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculate(vector<int> a, int x) {
    int ans = 0;
    int s = 0;
    int n = a.size();
    
    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        s += a[i];
    }
    
    int i = 0;
    // Iterate from the end of the array
    for (int j = n - 1; j >= 0; j--) {
        // Move i to find valid pairs
        while (i < n && s - a[i] - a[j] >= x) {
            i++;
        }
        ans += n - i; // Count valid pairs with a[j]
    }
    
    // Adjust for pairs where both elements are the same
    for (int j = 0; j < n; j++) {
        if (s - 2 * a[j] < x) {
            ans--;
        }
    }
    
    return ans / 2; // Each pair is counted twice
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        // Calculate the difference in valid pairs
        cout << (calculate(a, y + 1) - calculate(a, x)) << endl;
    }
}
