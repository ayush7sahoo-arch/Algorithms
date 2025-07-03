#include<iostream>
#include<vector>
using namespace std;

bool checkIfComplete(vector<pair<int,bool>>date){
    for(auto i:date){
        if(i.second==false){
            return false;
        }
    }
    return true;
}

void putTick(vector<pair<int,bool>>&date,int dig){
    for(auto &i:date){
        if(i.second==false && i.first==dig){
            i.second=true;
            return;
        }
    }
}


int main(){
    int t;
    cin>>t;
    vector<int>answer(t);
    for(int k=0;k<t;k++){
    vector<pair<int,bool>>date;
    date.push_back({0,false});
    date.push_back({1,false});
    date.push_back({0,false});
    date.push_back({3,false});
    date.push_back({2,false});
    date.push_back({0,false});
    date.push_back({2,false});
    date.push_back({5,false});
        int n;
        cin>>n;
        vector<int>digits(n);
        for(int i=0;i<n;i++){
            cin>>digits[i];
        }
        int ans=0;
        for(auto i:digits){
            if(checkIfComplete(date)){
                break;
            }
            putTick(date,i);
            ans++;
        }
        if(checkIfComplete(date)){
            answer[k]=ans;
        }
        else{
            answer[k]=0;
        }
        // cout<<"0*"<<endl;
        

        
    }
    for(int i=0;i<t;i++){
        cout<<answer[i]<<endl;
    }
}