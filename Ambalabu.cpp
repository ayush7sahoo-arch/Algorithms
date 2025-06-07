#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> ans(t,0);

    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        int max_val = a[0];
        for(int j=1;j<n;j++){
            if(a[j] > max_val){
                max_val = a[j];
            }
        }
        for(int j=0;j<n;j++){
            ans[i]+=max_val^a[j];
        }

    }
    for(int i=0;i<t;i++){
        cout << ans[i] << endl;
    }
}