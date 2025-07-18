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
    vector<int>p(n),s(n);
    for(auto &i:p)cin>>i;
    for(auto &i:s)cin>>i;

    if(p[n-1]==s[n-1]){

        for(int i=1;i<n-1;i++){
            if(lcm(p[i-1],s[i+1])%lcm(p[i],s[i])){
                cout<<"NO\n";return;
            }
        }
        cout<<"YES\n";

    }else{
        cout<<"NO\n";
    }
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