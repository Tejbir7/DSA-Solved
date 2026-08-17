#include<iostream>
#include<vector>
using namespace std;
 int maxScore(vector<int>& cardPoints, int k) {
    int n= cardPoints.size();
    if(!n) return 0;
    int totalPoints =0;
    int windowSum =0, count = 0;
    bool flag = true;
    for(int it: cardPoints) {
        totalPoints+=it;
        if(count ==n-k) flag = false;
        if(flag){
            windowSum+=it;
            ++count;
        }
    }
    if(k==n) return totalPoints;
    int l = 0, r=n-k, minPoints=windowSum;
    while(r<n){
        windowSum+= cardPoints[r]- cardPoints[l];
        minPoints = min(minPoints,windowSum);
        ++l; ++r;      
 }
return totalPoints - minPoints;     
}
    int main(){
        vector<int> cardPoints = {11,49,100,20,86,29,72};
        int k=4;
        int maxPoints = maxScore(cardPoints,k);
        cout << maxPoints<< endl;
        return 0;
    }