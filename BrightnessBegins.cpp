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
    int k;
    cin>>k;
    // cout<<k+ceil(sqrt(k))<<endl;
    int l=k;int h=2*k;
    int ans=0;
    while(l<=h){
        int m=l+(h-l)/2,a=m-floor(sqrt(m));
        if(a==k){ans=m;h=m-1;}
        if(a<k)l=m+1;
        else h=m-1;
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