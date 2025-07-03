#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e18;

#ifdef LOCAL_DEBUG
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x) 
#endif

void solve(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int total_alvaro_votes = 0;

    // The grid can be partitioned into 2x3 blocks. We find the max votes for each block.
    for (int i = 0; i < n; i += 3) {
        int block_max_votes = 0;

        // Configuration 1: Two horizontal 1x3 districts
        int count1_h = (s1[i] == 'A') + (s1[i+1] == 'A') + (s1[i+2] == 'A');
        int count2_h = (s2[i] == 'A') + (s2[i+1] == 'A') + (s2[i+2] == 'A');
        block_max_votes = max(block_max_votes, (int)((count1_h >= 2) + (count2_h >= 2)));

        // There are two ways to tile a 2x3 block with two L-trominoes.
        
        // Configuration 2: L-tromino Tiling A
        // District 1: (0,i), (0,i+1), (1,i)
        // District 2: (0,i+2), (1,i+1), (1,i+2)
        int count1_lA = (s1[i] == 'A') + (s1[i+1] == 'A') + (s2[i] == 'A');
        int count2_lA = (s1[i+2] == 'A') + (s2[i+1] == 'A') + (s2[i+2] == 'A');
        block_max_votes = max(block_max_votes, (int)(count1_lA >= 2) + (count2_lA >= 2));

        // Configuration 3: L-tromino Tiling B
        // District 1: (0,i), (1,i), (1,i+1)
        // District 2: (0,i+1), (0,i+2), (1,i+2)
        int count1_lB = (s1[i] == 'A') + (s2[i] == 'A') + (s2[i+1] == 'A');
        int count2_lB = (s1[i+1] == 'A') + (s1[i+2] == 'A') + (s2[i+2] == 'A');
        block_max_votes = max(block_max_votes, (int)(count1_lB >= 2) + (count2_lB >= 2));

        total_alvaro_votes += block_max_votes;
    }

    cout << total_alvaro_votes << endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}