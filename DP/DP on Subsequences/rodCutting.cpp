#include<bits/stdc++.h>
using namespace std;

//Recursive
//here recursion depends upon 3 states i,valueLeft,sum
   int dfs(int i,int valueLeft,int sum, vector<int> &price){
   if(valueLeft==0) return sum;

   if(i==0 && valueLeft>0){
   sum+= price[i]*valueLeft;
    return sum;
   }

    int notTake = 0, Take = 0;
    notTake += dfs(i-1,valueLeft,sum,price);
    if(valueLeft >= i+1){
        Take += dfs(i, valueLeft-(i+1), sum+price[i],price);
    }

    return max(Take,notTake);
}
    int cutRod(vector<int> &price) {
        // code here
          int n = price.size();
       int ans = dfs(n-1, n,0, price);
       return ans;
    }

    //memoization with 2 state dp
     int dfs(int i,int valueLeft,vector<int> &price, vector<vector<int>> &dp){
 
        if (valueLeft == 0) return 0;
   if(i==0){
    return price[0]*valueLeft;
   }
   if(dp[i][valueLeft]!= -1) return dp[i][valueLeft];

    int notTake = dfs(i-1,valueLeft,price,dp);
    int Take = INT_MIN;
    
    if(valueLeft >= i+1){
        Take = price[i] + dfs(i, valueLeft-(i+1), price,dp);
    }

    return dp[i][valueLeft] = max(Take,notTake);
}
    int cutRod(vector<int> &price) {
         // code here
        int n = price.size();
          vector<vector<int>> dp(n, vector<int>(n+1,-1));
       int ans = dfs(n-1, n, price,dp);
       return ans;
    }

   