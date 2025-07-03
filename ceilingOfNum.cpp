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

bool isPos(int n,int k){
    if(n>=k)return true;
    return false;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto &i:a)cin>>i;//sorted
    int s=0,e=n-1,ans=0;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(isPos(a[mid],k)){
            ans=a[mid];
            e=mid-1;
        }else{
            s=mid+1;
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