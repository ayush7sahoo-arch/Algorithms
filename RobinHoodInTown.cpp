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
    int sum=0;
    for(auto &i:a){cin>>i;sum+=i;}
    float avg=(float)sum/(float)n;
    if(n<3){
        cout<<-1<<endl;
    }else{
        sort(a.begin(),a.end());
        int c=0;
        for(int i=0;i<n;i++){
            if(a[i]<avg/2)c++;
        }
        if(c>n/2){
            cout<<0<<endl;
        }else{
            cout<<((2*n*(a[n%2?(n-1)/2:n/2]))-sum)+1<<endl;
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

    return 0;
}