#include <iostream>
#include <vector>
#include <algorithm>
#include <set> 
using namespace std;

bool can(int X, int n, int m, const std::vector<std::vector<int>>& a) {
    std::vector<std::pair<int, int>> problematic_cells;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == X) {
                problematic_cells.push_back({i, j});
            }
        }
    }

    if (problematic_cells.empty()) {
        return true;
    }



    int r_candidate = problematic_cells[0].first;
    int c_must_be = -1;
    bool possible1 = true; 
    for (const auto& p : problematic_cells) {
        if (p.first == r_candidate) {
            continue;
        }

        if (c_must_be == -1) {
            c_must_be = p.second;
        } else if (c_must_be != p.second) {
            possible1 = false;
            break;
        }
    }
    if (possible1) {
        return true;
    }

    int c_candidate = problematic_cells[0].second;
    int r_must_be = -1;
    bool possible2 = true;
    for (const auto& p : problematic_cells) {
        if (p.second == c_candidate) { 
            continue;
        }

        if (r_must_be == -1) {
            r_must_be = p.first;
        } else if (r_must_be != p.first) { 
            possible2 = false;
            break;
        }
    }
    if (possible2) {
        return true;
    }

    return false;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    int max_val_in_matrix = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
            if (a[i][j] > max_val_in_matrix) {
                max_val_in_matrix = a[i][j];
            }
        }
    }

    int low = 0;
    int high = max_val_in_matrix;
    int ans = max_val_in_matrix;

    if(can(ans,n,m,a)){
        ans--;
    }
    std::cout << ans<< std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}