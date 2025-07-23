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
    int n,x,p;
    cin>>n>>x>>p;
    string s;
    cin>>s;

    int l=x,r=x;
    int cur=x;
    for(auto i:s){
        if(i=='L')l=min(l,--cur);
        else r=max(r,++cur);
    }

    int ans=0;
    if(l<=0 && r>=0){
        int i=0;
        while(x!=0){
            x=s[i++]=='L'?x-1:x+1;
        }
        int j=0;
        ans=1;
        for(int k=0;k<n;k++){
            j+=(s[k]=='L'?-1:1);
            if(j==0){
                ans+=(p-i)/(k+1);break;
            }
        }
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