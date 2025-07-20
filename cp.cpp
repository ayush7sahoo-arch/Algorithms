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
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t = 1;
    // cin >> t;
    // while(t--){
    //     solve();
    // }

    set<int>s={1,4,2,3,2,12,1,1};
    // for(auto i:s){
    //     cout<<i<<endl;
    // }
    auto it=s.end();
    it--;
    cout<<*it<<endl;

    return 0;
}