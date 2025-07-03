#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) ++rank[px];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    // Step 1: Check if multisets are equal
    vector<int> freq_a(m + 1), freq_b(m + 1);
    for (int x : a) ++freq_a[x];
    for (int x : b) ++freq_b[x];
    for (int i = 1; i <= m; ++i) {
        if (freq_a[i] != freq_b[i]) {
            cout << "NO\n";
            return;
        }
    }

    // Step 2: Try all shifts
    for (int k = 0; k < n; ++k) {
        // Compute shifted array a'
        vector<int> a_prime(n);
        for (int i = 0; i < n; ++i) {
            a_prime[i] = a[(i + k) % n];
        }

        // Build graph using union-find
        UnionFind uf(n);
        for (int i = 0; i < n - 1; ++i) {
            if (abs(a_prime[i] - a_prime[i + 1]) >= 2) {
                uf.unite(i, i + 1);
            }
        }

        // Check if permutation is valid
        bool valid = true;
        vector<vector<int>> pos_b(m + 1);
        for (int i = 0; i < n; ++i) {
            pos_b[b[i]].push_back(i);
        }

        for (int v = 1; v <= m; ++v) {
            vector<int> pos_a;
            for (int i = 0; i < n; ++i) {
                if (a_prime[i] == v) pos_a.push_back(i);
            }
            if (pos_a.size() != pos_b[v].size()) {
                valid = false;
                break;
            }
            // Check if positions in pos_a map to pos_b[v] within same component
            if (!pos_a.empty()) {
                int root = uf.find(pos_a[0]);
                for (int i : pos_a) {
                    if (uf.find(i) != root) {
                        valid = false;
                        break;
                    }
                }
                for (int j : pos_b[v]) {
                    if (uf.find(j) != root) {
                        valid = false;
                        break;
                    }
                }
            }
        }

        if (valid) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}