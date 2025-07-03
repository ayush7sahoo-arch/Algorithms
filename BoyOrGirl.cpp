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
    string s;
    cin>>s;
    set<char>hehe;
    for(auto i:s){
        hehe.insert(i);
    }
    cout<<(hehe.size()%2?"IGNORE HIM!":"CHAT WITH HER!")<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t = 1;
    // cin >> t;
    // while(t--){
        solve();
    // }

    return 0;
}