#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long solve_case(long long n, long long x, long long y, long long vx, long long vy) {
    // Reduce velocity vector by gcd
    long long g = gcd(vx, vy);
    vx /= g;
    vy /= g;
    
    // Calculate tx and ty
    long long tx = -1, ty = -1;
    if (vx != 0 && (n - x) % vx == 0) {
        tx = (n - x) / vx;
    }
    if (vy != 0 && (n - y) % vy == 0) {
        ty = (n - y) / vy;
    }
    
    // Check if we can escape
    if (tx == -1 || ty == -1) {
        return -1;
    }
    if (tx != ty) {
        return -1;
    }
    
    // Calculate number of hits
    long long hits = (tx - 1) + (ty - 1) + (tx + ty) / 2 + abs(tx - ty) / 2;
    return hits;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, x, y, vx, vy;
        cin >> n >> x >> y >> vx >> vy;
        
        long long result = solve_case(n, x, y, vx, vy);
        cout << result << '\n';
    }
    
    return 0;
}
