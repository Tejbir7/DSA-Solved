#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
// Approach1: Brute force
 int sumSubarrayMinsBrute(vector<int>& arr) {
   int n = arr.size();
        const int MOD = 1e9 + 7;
        long long sum = 0;

        for(int i = 0; i < n; i++){
            int mini = arr[i];
            for(int j = i; j < n; j++){
                mini = min(mini, arr[j]);
                sum = (sum + mini) % MOD;
            }
        }
        return sum; 
    }
 // Approach 2: Stack
  int sumSubarrayMins(vector<int>& arr) {
           int n = arr.size();
        stack<int> st1;
        stack<int> st2;
        vector<int> prevSmaller(n);
        vector<int> nextSmaller(n);
        for(int i=0;i<n;++i){
        while(!st1.empty() && arr[st1.top()]> arr[i]) st1.pop();
        while(!st2.empty() && arr[st2.top()]>= arr[n-i-1]) st2.pop();
        prevSmaller[i] = st1.empty() ? -1 : st1.top();
        nextSmaller[n-i-1] = st2.empty() ? n : st2.top();
        st1.push(i);
        st2.push(n-i-1);
        }
        long long sum = 0;
        const int MOD = (int)1e9 + 7;
        for(int i=0;i<n;++i){
            int leftContribution = i-prevSmaller[i];
            int rightContribution = nextSmaller[i] - i;
            long long contribution = leftContribution * rightContribution;
            long long temp = arr[i]* contribution;
            sum = (sum+temp) % MOD;
        }
        return sum;
    }