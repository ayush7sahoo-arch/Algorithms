#include<iostream>
#include<vector>
using namespace std;

typedef struct Node{
    char c;
    int n;
}Node;

int main(){
    int t;
    cin>>t;
    vector<int>ans(t);
    
    
    for(int i=0;i<t;i++){
        vector<int>alfa(26,0);
        int num;
        cin>>num;
        string s;
        cin>>s;
        for(int j=0;j<num;j++){
            (alfa[s[j]-'A'])++;
        }
        // for(int j=0;j<26;j++){
        //     cout<<alfa[j]<<", ";
        // }
        // cout<<endl;
        for(int j=0;j<alfa.size();j++){
            int time=j+1;
            if(alfa[j]>=time){
                ans[i]++;
            }
        }
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
}