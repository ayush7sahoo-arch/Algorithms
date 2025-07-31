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
    bool inc=true;
    string ans="";
    int l=0,r=n-1;
    while(l<=r){
        if(l==r){
            ans+="L";
            break;
        }
        if(inc){
            if(a[l++]<a[r--]){
                ans+="LR";
            }else{
                ans+="RL";
            }
        }else{
            if(a[l++]<a[r--]){
                ans+="RL";
            }else{
                ans+="LR";
            }
        }
        inc=!inc;
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