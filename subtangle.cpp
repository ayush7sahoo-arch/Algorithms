#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define vi(a,n) vector<int>a(n)
#define input(a) for(auto&i:(a))cin>>i
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
    int l,n,m;
    cin>>l>>n>>m;

    vi(a,l);
    input(a);
    vector<vector<int>>mat(n,vector<int>(m));
    for(auto&i:mat)input(i);

    vector<vector<bool>>dpnext(n+2,vector<bool>(m+2,false));

    for(int k=l-1;k>=0;k--){

        vector<vector<bool>>dpcur(n+2,vector<bool>(m+2,false));
        for(int r=n-1;r>=0;r--){
            for(int c=m-1;c>=0;c--){
                // choosing the curr rc else in the subrect 
                //if there is a way of winning
                if((mat[r][c]==a[k] && !dpnext[r+1][c+1])||(dpcur[r+1][c]||dpcur[r][c+1]))dpcur[r][c]=true;

            }
        }
        dpnext=dpcur;
        
    }

    cout<<((dpnext[0][0])?"T\n":"N\n");
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