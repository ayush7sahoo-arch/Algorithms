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
    int n,m,k;
    cin>>n>>m>>k;
    vector<string>a(n);
    for(auto&i:a)cin>>i;

    k--;
    int g=0;
    vector<vector<int>>gold(n+1,vector<int>(m+1,0));
    // gold[0][0]=a[0][0]=='g';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='g')g++;
            gold[i+1][j+1]=gold[i+1][j]+gold[i][j+1]-gold[i][j]+(a[i][j]=='g');
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<gold[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int loss=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(a[i][j]=='.'){
            int a=max(0ll,i-k),b=min(i+k+1,n),c=max(0ll,j-k),d=min(j+k+1,m);
            int cur=gold[b][d]+gold[a][c]-gold[a][d]-gold[b][c];
            loss=min(loss,cur);}
        }
    }

    cout<<g-loss<<endl;
    
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