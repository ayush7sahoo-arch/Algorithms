#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int> ans(t);
    for(int i=0;i<t;i++){
        ans[i]=0;
        int n;
        cin>>n;
        list<int> arr; // Using list to allow easy removal of elements
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            arr.push_back(temp); // Store elements in a list
        }
        auto it = arr.begin();
        while (it != arr.end()) {
            if (it != arr.begin() && !(*it > *(--it) + 1)) {
                it = arr.erase(++it); // Remove the element if condition fails
            } else {
                ++it; // Move to the next element
            }
        }
        it= arr.begin();
        while(it!=arr.end()){
            cout<<*it<<" ";
            ++it; // Move to the next element
        }
        
        
        it = arr.begin();
        while (it != arr.end()) {
            if (it != arr.begin() && (*it > *(--it) + 1)) {
                ans[i]++; // Increment count if condition is met
            }
            ++it; // Move to the next element
        }
        ans[i]++; // Increment for the first element

    }
    // for(int i=0;i<t;i++){
    //     cout<<ans[i]<<endl;
    // }
    return 0;
}