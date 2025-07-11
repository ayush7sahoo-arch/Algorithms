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
    vector<int>b=a;
    sort(all(b),greater<int>());
    bool rep=false;
    bool rs=true;
    for(int i=0;i<n-1;i++){
        if(b[i]==b[i+1])rep=true;
        if(a[i]<a[i+1])rs=false;
    }
    // cout<<rs<<endl;
    if(rs && !rep)cout<<"NO\n";
    else cout<<"YES\n";
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