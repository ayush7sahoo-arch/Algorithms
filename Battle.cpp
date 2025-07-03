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
    string s;
    cin>>s;
    int ones=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')
        ones++;
    }
    int zeros=n-ones;

    if(ones<=k){
        cout<<"Alice\n";
    }else if(2*k>n){
        cout<<"Alice\n";
    }else{
        cout<<"BOB\n";
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