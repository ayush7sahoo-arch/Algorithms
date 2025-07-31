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
    for(auto &i:a)cin>>i;
    
    // if(a[n-2]>=a[n-1]){
    //     cout<<"YES\n";
    // }else{
    //     cout<<"NO\n";
    // }

    int minPref=a[0];
    bool pos=true;
    for(int i=0;i<n;i++){
        if(a[i]>minPref*2-1){
            pos=false;
            break;
        }
        minPref=min(a[i],minPref);
    }
    if(pos){
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