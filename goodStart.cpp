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
    int w,h,a,b;
    cin>>w>>h>>a>>b;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    int hGap=abs(x1-x2);
    int vGap=abs(y1-y2);

    if(hGap%a==0 && hGap>0){
        cout<<"YES\n";
    }else if(vGap%b==0 && vGap>0){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
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