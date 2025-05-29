#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> ans(t, 0); // Initialize ans with zeros
    vector<int> node(0);
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int j=0;j<n;j++){
            cin >> arr[j]; // Read values into arr
        }
        sort(arr.begin(), arr.end()); // Sort the array in ascending order
        for(int j=0, k=1;j<n;j++,k++){
            if(j==0 && k==1){
                node.push_back(arr[j] + arr[k]); // Add the first two elements
                j++;k++;
            }else if(k==n){
                node.push_back(node.back() + arr[j]); // Add the last element to the last node
                break; // Exit the loop as we have processed all elements
            }
            else if(node.size()>0 && (node.back()<arr[j] || node.back() < arr[k])){
                node.push_back(node.back() + arr[j]); // Add current element to the last node
            }else{
                node.push_back(arr[j] + arr[k]); // Add the current pair of elements
            }
        }
        // Calculate the sum of all nodes
        for(int j=0;j<node.size();j++){
            ans[i] += node[j]; // Accumulate the sum of nodes
        }
        for(int j=0;j<node.size();j++){
            cout << node[j] << " "; // Print the nodes for debugging
        }
        node.clear(); // Clear the node vector for the next test case
    }
    for(int i=0;i<t;i++){
        cout << ans[i] << endl; // Print the result for each test case
    }
    return 0;
}