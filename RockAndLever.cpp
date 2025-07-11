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

    for(auto &i:a)i=(1<<(__bit_width(i)-1));
    sort(all(a));
    int ans=0;
    vector<pair<int,int>>c;
    for(auto i:a){
        if(c.empty()){
            c.push_back(mp(i,1));
            continue;
        }
        if(c.back().F==i)(c.back().S)++;
        else c.push_back(mp(i,1));
    }
    for(auto i:c){
        ans+=(i.S*(i.S-1))/2;
    }
    cout<<ans<<endl;
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

    // int n;
    // cin>>n;
    // int x=__bit_width(n);
    // cout<<x<<endl;

    return 0;
}