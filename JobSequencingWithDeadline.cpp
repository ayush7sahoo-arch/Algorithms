#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >>t;
    vector<float> ans(t, 0.0f); // Initialize ans with zeros
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<pair<int, int>> jobs(n);
        for(int j=0;j<n;j++){
            cin>> jobs[j].first; // Read value
        }
        for(int j=0;j<n;j++){
            cin>> jobs[j].second; // Read deadline
        }
        // Sort jobs by value in descending order
        sort(jobs.begin(), jobs.end(),[](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first > b.first; // Sort by value in descending order
            }
        );
        vector<bool> slot(n, false); // Track used slots
        for(int j=0;j<n;j++){
            // Try to place the job in the latest available slot before its deadline
            for(int k=min(n, jobs[j].second) - 1; k >= 0; k--){
                if(!slot[k]){
                    slot[k] = true; // Mark this slot as used
                    ans[i] += jobs[j].first; // Add job value to the answer
                    break; // Job is placed, break out of the loop
                }
            }
        }

    }
    for(int i=0;i<t;i++){
        cout << ans[i] << endl; // Print the result for each test case
    }
    return 0;

}