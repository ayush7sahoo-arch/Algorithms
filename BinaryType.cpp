#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string num;
        cin>>num;
        int ans=0;

        int flips=0;
        for(int i=0;i<num.length()-1;i++){
            if(num[i]!=num[i+1])flips++;
        }

        if(flips==0){
            ans=n+(num[0]=='1');
        }else if(flips==1){
            ans=n+flips;
        }else if(flips==2){
            ans=n+flips-1;
        }else if(flips>2){
            ans=n+flips+(num[0]=='1')-2;
        }
        cout<<ans<<endl;
    }
}