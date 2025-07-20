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
    string s;
    cin>>s;


    int c=n;
    vector<int>ans(n);
    for(int i=n-1;i>0;i--){
        if(s[i-1]=='>')ans[i]=c--;
    }
    c=1;
    for(int i=n-1;i>0;i--){
        if(s[i-1]=='<')ans[i]=c++;
    }
    ans[0]=c;
    
    for(auto i:ans)cout<<i<<" ";
    cout<<endl;
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