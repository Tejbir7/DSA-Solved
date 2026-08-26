#include<bits/stdc++.h>
using namespace std;
// common Recursive call: weak would give tle on 7/84
bool helper(int i,int count,const int n,const string&s){
    if(count <0) return false;
    if(i==n) return count==0;
  
    if(s[i] == '(') ++count;
    else if(s[i] == ')'){
        --count;
        if(count < 0) return false;
    } 
     else{
        //here if evaluates every possibility
        if(helper(i+1,count+1, n,s) || helper(i+1,count-1, n, s) || helper(i+1,count,n,s)) return true;
     }

     return helper(i+1,count,n,s);
 }

 bool checkValidString(const string &s) {
        int n = s.size();
       // vector<vector<int>> dp(n, vector<int>(n,-1));
       return helper(0,0,n,s);
    }


    //Better version: tle on 81/84
    bool helper(int i,int count,const int n,const string&s){
    if(count <0) return false;
    if(i==n) return count==0;
  
    if(s[i] == '(') return helper(i+1,count+1,n,s);
    if(s[i] == ')') return helper(i+1,count-1,n,s);
    return (helper(i+1,count+1, n,s) || helper(i+1,count-1, n, s) || helper(i+1,count,n,s));
 }
  bool checkValidString(const string &s) {
        int n = s.size();
       // vector<vector<int>> dp(n, vector<int>(n,-1));
       return helper(0,0,n,s);
    }

 //Memoised

    bool helper(int i,int count,const int n,const string&s,vector<vector<int>> &dp){
    if(count <0) return false;
    if(i==n) return count==0;
    if(dp[i][count] != -1) return dp[i][count];
  
    if(s[i] == '(') return dp[i][count]= helper(i+1,count+1,n,s,dp);
    if(s[i] == ')') return dp[i][count]= helper(i+1,count-1,n,s,dp);
    return dp[i][count]= (helper(i+1,count+1, n,s,dp) || helper(i+1,count-1, n, s,dp) || helper(i+1,count,n,s,dp));
 }

 bool checkValidString(const string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return helper(0,0,n,s,dp);
    }

    //optimal greedy soln 
     bool checkValidString(const string &s) {
        int n = s.size();
        int mini = 0;
        int maxi = 0;
        for(int i=0; i<n; ++i){
            if(s[i] == '('){
                ++mini; ++maxi;
            }
            else if(s[i] == ')'){
                --mini;
            }else{
                --mini; ++maxi;
            }
            if(mini<0) mini = 0;
            if(maxi<0) return false;
        }
        return true;
    }