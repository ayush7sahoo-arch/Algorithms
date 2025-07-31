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
    string l,r;
    cin>>l>>r;

    if(l==r){
        cout<<2*l.size()<<endl;
    }else{
        int i=0;

        while(i<l.size() && l[i]==r[i])i++;
        int ans=i;
        if(l[i]+1<r[i]){
            cout<<2*ans<<endl;
        }else{
            ans*=2;
            ans++;
            i++;
            while(i<l.size() && l[i]=='9' && r[i]=='0'){
                i++,ans++;
            }
            cout<<ans<<endl;

        }
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

    // cout<<cal(345,305)<<endl;
    return 0;
}