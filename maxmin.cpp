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
    vector<int>mintill(n);
    mintill[0]=a[0];
    for(int i=1;i<n;i++){
        mintill[i]=min(mintill[i-1],a[i]);
    }
    vector<int>maxtill(n);
    maxtill[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        maxtill[i]=max(maxtill[i+1],a[i]);
    }

    string ans="";
    for(int i=0;i<n;i++){
        if(a[i]==mintill[i]||a[i]==maxtill[i]){
            ans+="1";
        }else{
            ans+="0";
        }
    }
    // ans+="1";
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