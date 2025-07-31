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
    int x,y;
    cin>>x>>y;
    if(x==y && x!=0){
        cout<<-1<<endl;
    }else{
        int ans=0;
        while((x+ans+y+ans)!=(x+ans)^(y+ans)){
            int mask=1;
            // int i=0;
            while(!((x+ans)&mask && (y+ans)&mask)){
                mask=mask<<1;
            }
            // mask=mask>>1;
            // x+=mask;
            // y+=mask;
            ans+=mask;
        }
        cout<<ans<<endl;
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