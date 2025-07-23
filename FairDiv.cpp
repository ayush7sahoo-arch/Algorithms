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
    int s=0;
    for(auto&i:a){cin>>i;s+=i;}
    if(s%2!=0){
        cout<<"NO\n";
    }else{
        sort(all(a));
        int cur=0;
        for(int i=n-1;i>=0;i--){
            if(cur+a[i]<=s/2)cur+=a[i];
        }
        if(cur==s/2)cout<<"YES\n";
        else cout<<"NO\n";
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