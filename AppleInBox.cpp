#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<string> ans(t);
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        int max=arr[0];
        int min=arr[0];
        int sum=0;
        int maxNo=0;
        
        for(int j=0;j<n;j++){
            sum+=arr[j];
            if(arr[j]>max){
                max=arr[j];
            }
            if(arr[j]<min){
                min=arr[j];
            }
        }
        for(int j=0;j<n;j++){
            if(arr[j]==max){
                maxNo++;
            }
        }
        if(max-min-1>k && maxNo==1){
            ans[i]="Jerry";
        }else if(max-min>k && maxNo>1){
            ans[i]="Jerry";
        }
        else{
            if(sum%2==0){
                ans[i]="Jerry";
            }else{
                ans[i]="Tom";
            }
    }
    
}
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}