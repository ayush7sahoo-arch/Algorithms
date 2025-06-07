#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a,int b){
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(){
    int t;
    cin>>t;
    vector<int> ans(t);
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        int g = arr[0];
        for(int j=1;j<n;j++){
            g = gcd(g, arr[j]);
        }

        int gcount=0;
        for(int j=0;j<n;j++){
            if(arr[j]==g){
                gcount++;
            }
        }

        if(gcount>0){
            for(int k=0;k<n;k++){
                    if(arr[k]!=g){
                        ans[i]++;
                    }
                }
        }
        else{
            sort(arr.begin(), arr.end());
            int count=0;
            
            while(arr[0]!=g){
                for(int j=1;j<n;j++){
                    if(arr[0]>gcd(arr[0], arr[j])){
                        arr[0] = gcd(arr[0], arr[j]);
                    }
                }
                count++;
            }
            for(int j=0;j<n;j++){
                if(arr[j]!=g){
                    ans[i]++;
                }
            }
            ans[i] += count;
            
        
        }

        

    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
}