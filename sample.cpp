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
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){ cin >> a[i];sum += a[i]; }

    int happy=0;
    for(int i=0;i<n;i++){
        happy+=a[i]%2?a[i]-1:a[i];
    }
    int left=k-happy/2;
    int sad=sum-happy;

    cout<<happy+(sad<=left?sad:(2*left-sad))<<endl;


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