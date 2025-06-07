#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<vector<int>> ans(t);
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> p(2*n);
        int g[n][n];
        for(int k=0;k<n;k++){
            for(int j=0;j<n;j++){
                cin>>g[k][j];
            }
        }
        // for(int k=0;k<n;k++){
        //     for(int j=0;j<n;j++){
        //         cout<<g[k][j]<< " ";
        //     }
        // }
        vector<bool> used(2*n, false);
        for(int j=0;j<n;j++){
            for(int k=0;k<=j;k++){
                p[j+k+1] = g[k][j];
                used[p[j+k+1]-1] = true;
            }
        }
        for(int j=0;j<2*n;j++){
            if(!used[j]){
                p[0] = j+1;
            }
        }
        ans[i]= p;
    }
    for(int i=0;i<t;i++){
        for(int j: ans[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}