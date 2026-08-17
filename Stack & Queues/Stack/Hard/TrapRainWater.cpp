#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
//approach 1 by me: calculate the boundaries first by prefix max
 int trap(vector<int>& height) {
    int n = height.size();
    int leftMax=-1, rightMax = -1;
    vector<int>left(n,-1);
    vector<int>right(n,-1);
    for(int i=0;i<n;++i){
        if(leftMax> height[i])left[i] = leftMax;
        if(rightMax>height[n-i-1]) right[n-i-1] = rightMax;
        if(height[i]>leftMax) leftMax = height[i];
        if(height[n-i-1]>rightMax) rightMax = height[n-i-1];        
    }
    int trapped =0;
   for(int i=0;i<n;++i){
    if(left[i] == -1 || right[i] == -1) continue;
    else{
        trapped += (min(left[i],right[i])- height[i]);
    }
   }
   return trapped;        
    }
    //Cleaner for same approach
    int trap(vector<int>& height) {
    int n = height.size();
    vector<int> left(n), right(n);
    int leftMax = 0, rightMax = 0;
    for(int i=0;i<n;i++) {
        left[i] = leftMax;
        leftMax = max(leftMax, height[i]);
        right[n-i-1] = rightMax;
        rightMax = max(rightMax, height[n-i-1]);
    }
    int trapped = 0;
    for(int i=0;i<n;i++) {
        int h = min(left[i], right[i]) - height[i];
        if(h > 0) trapped += h;
    }
    return trapped;
}

    //approach 2: 2 ptr
    int trap(vector<int>& height){
        int n = height.size();
        int l = 0, trapped =0, lMax=0, rMax=0;
        int r = n-1;
        while(l<r){
            if(height[l]<= height[r]){
            if(lMax> height[l]) trapped += lMax - height[l];
            else lMax = height[l];    
            ++l;   
        }else{
            if(rMax> height[r]) trapped += rMax - height[r];
            else rMax = height[r];            
            --r;
        }
    }
    return trapped;
}

//Flop approach of finding the pge and nge 
//  int trap(vector<int>& height) {
//     int n = height.size();
//     vector<pair<int,int>> boundaries(n, {0, 0});
//     stack<int> pge;
//     stack<int>nge;
//     for(int i=0; i<n; ++i){
//         int j = n-i-1;
//         while( !pge.empty() && height[pge.top()] < height[i]) pge.pop();
//         while( !nge.empty() && height[nge.top()] < height[j]) nge.pop();
//         boundaries[i].first = pge.empty() ? -1 : pge.top();
//         boundaries[j].second = nge.empty() ? n : nge.top();
//         pge.push(i);
//         nge.push(j);        
//     }
//     int trapped = 0;
//     for(int i=0;i<n;++i){
//         if(boundaries[i].first == -1 || boundaries[i].second == n) continue;
//         trapped += min(height[boundaries[i].first], height[boundaries[i].second]) - height[i];
//     }   
//     return trapped;     
//     }