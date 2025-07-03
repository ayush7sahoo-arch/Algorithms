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
    int n,x;
    cin >> n >> x;

    vector<int> a(n);
    int sum = 0;
    int maxV=0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];sum+= a[i];
        if(a[i] > maxV) maxV = a[i];
    }
    int avg=(sum-1)/x+1;
    cout<<max(avg,maxV)<<endl;
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