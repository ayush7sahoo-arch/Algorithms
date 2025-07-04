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
    cin>>n>>k;
    vector<int>a(n);
    for(auto&i:a)cin>>i;
    sort(all(a));

    for(int i=n-2;i>=0&&k>0;i-=2){
        int t=min(k,a[i+1]-a[i]);
        a[i]+=t;
        k-=t;
    }
    int ans=0;
    for(int i=n-1;i>=0;i-=2){   
        ans+=a[i];
    }
    for(int i=n-2;i>=0;i-=2){
        ans-=a[i];
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

    return 0;
}