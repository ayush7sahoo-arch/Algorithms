#include<iostream>
using namespace std;


string solve(){
    int l1,b1,l2,b2,l3,b3;
    cin>>l1>>b1>>l2>>b2>>l3>>b3;
    if(l1==l2 && l2==l3 && b1+b2+b3==l1)return "Yes";
    if(l1==l2+l3 && b2==b3 &&l1==b1+b2)return "YES";
    if(b1==b2 && b2==b3 && l1+l2+l3==b1)return "YES";
    if(b1==b2+b3 && l2==l3 && b1==l1+l2)return "YES";
    return "NO";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
}