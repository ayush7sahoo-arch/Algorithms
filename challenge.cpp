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
    if(n<3){
        cout<<n<<endl;
        return;
    }
    if(n%2==0){
        if(n%3==0)cout<<(n-1)*(n-2)*(n-3)<<endl;
        else cout<<n*(n-1)*(n-3)<<endl;
        return; 
    }else{
        cout<<n*(n-1)*(n-2)<<endl;
        return;
    }
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