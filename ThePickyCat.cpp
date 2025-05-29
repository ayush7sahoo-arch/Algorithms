#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<string>ans(t);
    for(int i=0;i<t;i++){
        int n;

        cin>>n;
        vector<int>arr(n);
        int median;
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            if(j==0){
                median = temp; // Initialize median with the first element
            }
            arr.push_back(temp);
            arr.push_back(-1*temp);

        }
        sort(arr.begin(), arr.end());
        int l,r;
        for(int j=0;j<n;j++){
            if(arr[j]==median || arr[j]==-1*median){
                l=j;r=j+2*(n-j)-1;
                break;
            }
        }

    if(r-l-1<=n){
            ans[i] = "YES";
        }else{
            ans[i] = "NO";
        }
    }

        for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
