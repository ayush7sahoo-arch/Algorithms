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
    string s;
    cin>>s;
    int n;
    vector<pair<int, int>>a(n);
    for(int i=0;i<n;i++)cin>>a[i].F>>a[i].S;

    int c=0;
    for(int i=0;i<s.length()-5;i++){
        if(s[i]=='d' && s[i+1]=='o' && s[i+2]=='c' && s[i+3]=='k' && s[i+4]=='e' && s[i+5]=='r')c++;
    }
    int r=INT_MAX,l=INT_MIN;
    for(int i=0;i<n;i++){
        l=max(l,a[i].F);
        r=min(r,a[i].S);
    }

    l*=6;
    r*=6;
    
    int ans=0;
    if()
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