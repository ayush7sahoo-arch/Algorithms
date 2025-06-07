#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

long long solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    bool allsame = true;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (i > 0 && a[i] != a[i - 1]) {
            allsame = false;
        }
    }

    if (allsame) {
        return 0;
    }

    long long min_cost = -1;

    
    for (int i = 0; i < n; ++i) {
        long long current_cost = (long long)(n - 1) * a[i];
        if (min_cost == -1 || current_cost < min_cost) {
            min_cost = current_cost;
        }
    }

    for (int s = 0; s < n; ++s) {

        int e = s;
        while (e + 1 < n && a[e + 1] == a[s]) {
            e++;
        }
        
        long long val = a[s];
        long long cost_left_fill = 0;
        if (s > 0) { 
            cost_left_fill = (long long)s * val;
        }
        
        long long cost_right_fill = 0;
        if (e < n - 1) {
            cost_right_fill = (long long)(n - 1 - e) * val;
        }
        
        long long current_total_cost = cost_left_fill + cost_right_fill;
        
        if (min_cost == -1 || current_total_cost < min_cost) {
            min_cost = current_total_cost;
        }

        s = e; 
    }


    return min_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << std::endl;
    }
    return 0;
}

