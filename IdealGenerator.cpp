#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<string> ans(t);
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        if(n%2==0){
            ans[i]="NO";

        }else{
            ans[i]="YES";
        }
    }
    for(int i=0;i<t;i++){
        cout << ans[i] << endl;
    }
    return 0;
}