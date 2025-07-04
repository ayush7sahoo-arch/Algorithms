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
    int l,r,L,R;
    cin>>l>>r>>L>>R;
    int ans=0;
    if(L>=r){
        ans=1+(L==r);
    }else if(l>=R){
        ans=1+(l==R);
    }else if(L<=r && L>l){
        ans=min(r-L,R-L)+1+(r!=R);
    }else if(l<=R && l>L){
        ans=min(R-l,r-l)+1+(r!=R);
    }else if(l==L){
        ans=min(R-l,r-l)+(r!=R);
    }else{
        ans=min(l-R,L-r)+2;
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