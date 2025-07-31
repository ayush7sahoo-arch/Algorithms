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
    cin>>n;
    vector<int>a(n);
    for(auto&i:a)cin>>i;
    int mx=*max_element(all(a));
    sort(all(a));
    vector<pair<int,int>>c;
    for(int i=0;i<n;i++){
        if(c.empty())c.pb(mp(a[i],1));
        else{
            if(c.back().F==a[i])c.back().S++;
            else c.pb(mp(a[i],1));
        }
    }
    for(int i=c.size()-1;i>=0;i--){
        if(c[i].S%2){
            cout<<"YES\n";return;
        }
    }
    cout<<"NO\n";
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