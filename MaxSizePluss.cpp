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

    int ans1=0,max1=INT_MIN;
    for(int j=0;j<n;j=j+2){
        if(a[j]>max1)max1=a[j];
        ans1++;
    }


    int ans2=0,max2=INT_MIN;
    for(int j=1;j<n;j=j+2){
        if(a[j]>max2)max2=a[j];
        ans2++;
    }
    
    cout<<max(max1+ans1,max2+ans2)<<endl;

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