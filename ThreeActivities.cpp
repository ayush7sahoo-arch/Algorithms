#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> ans(t, 0); // Initialize the answer vector with zeros
    for(int i = 0; i < t; i++){
        int n;
        cin >> n; // Read the size of the arrays
        vector<int> a(n), b(n), c(n);
        
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }
        for(int j = 0; j < n; j++){
            cin >> b[j];
        }
        for(int j = 0; j < n; j++){
            cin >> c[j];
        }

        priority_queue<int> maxes;
        for(int j = 0; j < n; j++){
            maxes.push(max(max(a[j], b[j]), c[j]));
        }

        // Sum the top 3 maximum values
        for(int j = 0; j < 3 && !maxes.empty(); j++){
            ans[i] += maxes.top();
            maxes.pop();
        }
    }
    
    for(int i = 0; i < t; i++){
        cout << ans[i] << endl;
    }
}
