#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    vector<string> ans(t);
    for(int i=0; i<t; i++){
        int x;
        int k;
        cin>>x>>k;
        if(k==1){
            ans[i]=isPrime(x)?"YES":"NO";
        }
        else{
            if(x==1 && k==2){
                ans[i]="YES";
            }
            else{
                ans[i]="NO";
            }
        }

    }
    for(int i=0; i<t; i++){
        cout<<ans[i]<<endl;
    }
    return 0;

        
}