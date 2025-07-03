#include<iostream>
#include<vector>
using namespace std;

string solve(){
    int n;
    cin>>n;
    vector<int>a(1001,0);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a[t]++;
    }
    for(int i=1;i<=1000;i++){
        if(a[i]>=2){
            int carry=a[i]-2;
            a[i+1]+=carry;
            a[i]-=carry;
        }
    }
    for(auto i:a){
        if(i%2!=0)return "NO";
    }
    return "YES";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}
