#include <bits/stdc++.h> // Includes everything, but generally good practice to include specific headers

using namespace std;

#define int long long // This is fine for competitive programming
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define endl '\n'

const int MOD = 1e9 + 7; // Not used in this problem
const int INF = 1e18;   // Not used in this problem

#ifdef LOCAL_DEBUG
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x) 
#endif

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    int idx=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1 && a[i]!=-1)idx=i;
    }
    set<int>ans;
    ans.insert(0); // Always include empty subarray sum

    if(idx==-1){
        int currPr=0;
        int maxPrTilNow=0; // max prefix sum encountered so far (including 0)
        int minPrtilNow=0; // min prefix sum encountered so far (including 0)
        int maxSum=0;     // max subarray sum found
        int minSum=0;     // min subarray sum found

        for(int i=0;i<n;i++){
            currPr+=a[i];
            // To get max subarray sum ending at current point: current_sum - min_prefix_before_it
            maxSum=max(maxSum,currPr-minPrtilNow); 
            // To get min subarray sum ending at current point: current_sum - max_prefix_before_it
            minSum=min(minSum,currPr-maxPrTilNow);
            
            maxPrTilNow=max(maxPrTilNow,currPr); // Update max prefix sum
            minPrtilNow=min(minPrtilNow,currPr); // Update min prefix sum
        }
        for(int i=minSum;i<=maxSum;i++){
            ans.insert(i);
        }

    }else{
        // ------------- Subarrays entirely to the left of x -------------
        if (idx > 0) {
            int current_prefix_sum = 0;
            int min_prefix_so_far = 0; 
            int max_prefix_so_far = 0; 
            int min_overall_sum_L = 0; 
            int max_overall_sum_L = 0; 

            for (int i = 0; i < idx; ++i) {
                int val = a[i];
                current_prefix_sum += val;
                min_overall_sum_L = min(min_overall_sum_L, current_prefix_sum - max_prefix_so_far); 
                max_overall_sum_L = max(max_overall_sum_L, current_prefix_sum - min_prefix_so_far); 
                min_prefix_so_far = min(min_prefix_so_far, current_prefix_sum);
                max_prefix_so_far = max(max_prefix_so_far, current_prefix_sum);
            }
            
            for (int s = min_overall_sum_L; s <= max_overall_sum_L; ++s) {
                ans.insert(s);
            }
        }
        
        // ------------- Subarrays entirely to the right of x -------------
        if (idx < n - 1) {
            int current_prefix_sum = 0;
            int min_prefix_so_far = 0; 
            int max_prefix_so_far = 0; 
            int min_overall_sum_R = 0; 
            int max_overall_sum_R = 0; 

            for (int i = idx + 1; i < n; ++i) {
                int val = a[i];
                current_prefix_sum += val;
                min_overall_sum_R = min(min_overall_sum_R, current_prefix_sum - max_prefix_so_far);
                max_overall_sum_R = max(max_overall_sum_R, current_prefix_sum - min_prefix_so_far);
                min_prefix_so_far = min(min_prefix_so_far, current_prefix_sum);
                max_prefix_so_far = max(max_prefix_so_far, current_prefix_sum);
            }
            
            for (int s = min_overall_sum_R; s <= max_overall_sum_R; ++s) {
                ans.insert(s);
            }
        }

        // ------------- Subarrays containing idx -------------
        // Need min/max of suffix sums for left part and min/max of prefix sums for right part
        // These are the 'min_suff_L' and 'max_suff_L' variables in my previous C++ code.

        int current_sum_L_suffix = 0;
        int min_suff_L_range = 0; // Represents min suffix sum of a[0...idx-1] (including empty suffix 0)
        int max_suff_L_range = 0; // Represents max suffix sum of a[0...idx-1] (including empty suffix 0)
        for (int i = idx - 1; i >= 0; --i) {
            current_sum_L_suffix += a[i];
            min_suff_L_range = min(min_suff_L_range, current_sum_L_suffix);
            max_suff_L_range = max(max_suff_L_range, current_sum_L_suffix);
        }
        
        int current_sum_R_prefix = 0;
        int min_pref_R_range = 0; // Represents min prefix sum of a[idx+1...n-1] (including empty prefix 0)
        int max_pref_R_range = 0; // Represents max prefix sum of a[idx+1...n-1] (including empty prefix 0)
        for (int i = idx + 1; i < n; ++i) {
            current_sum_R_prefix += a[i];
            min_pref_R_range = min(min_pref_R_range, current_sum_R_prefix);
            max_pref_R_range = max(max_pref_R_range, current_sum_R_prefix);
        }
        
        int min_combined_sum_with_x = min_suff_L_range + a[idx] + min_pref_R_range;
        int max_combined_sum_with_x = max_suff_L_range + a[idx] + max_pref_R_range;

        for (int s = min_combined_sum_with_x; s <= max_combined_sum_with_x; ++s) {
            ans.insert(s);
        }
    }

    cout<<ans.size()<<endl;
    bool first = true;
    for(auto i:ans){
        if (!first) {
            cout << " ";
        }
        cout<<i;
        first = false;
    }
    cout<<endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

}