#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 int maxArea(vector<int>& height) {
    int n = height.size();
    int i=0,j=n-1,area;
    int maxA =0;
    while(i<j){
        area = (j-i)*min(height[i],height[j]);
        maxA=max(maxA,area);
        if(height[i]<height[j]) ++i;
        else --j;
    }
    return maxA;        
    }