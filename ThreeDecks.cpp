#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<string>ans(t);
    for(int i=0;i<t;i++){
        vector<int>arr(3);
        int sum=0;
        for(int i=0;i<3;i++){
            cin>>arr[i];
            sum+=arr[i];
        }

        if(sum%3==0){
            if(arr[0]<=sum/3 && arr[1]<=sum/3){
                ans[i]="YES";
            }else{
                ans[i]="NO";
            }

        }else{
            ans[i]="NO";
        }
        
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
}