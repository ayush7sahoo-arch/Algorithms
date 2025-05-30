#include<iostream>
#include<vector>
using namespace std;

int fib(int n,vector<int>& memo) {
    if (n <= 1) return n;
    if(memo[n] != -1) return memo[n];
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}
int _fib(int n){
    if (n <= 1) return n;
    return _fib(n - 1) + _fib(n - 2);
}

int fib_iter(int n){
    if(n <= 1) return n;
    vector<int>f(n+1);
    f[0] = 0;
    f[1] = 1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-2]+f[i-1];
    }
    return f[n];
}

int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    vector<int> memo(n + 1, -1); // Initialize memoization array with -1
    int result = fib_iter(n);
    
    cout << "Fibonacci number at position " << n << " is: " << result << endl;
    
    return 0;
}
