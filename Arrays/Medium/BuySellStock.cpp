#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit =0,minPrice= INT_MAX,ptr =0;
        for(int price : prices){
        minPrice = min(minPrice,price);
        maxProfit = max(maxProfit,price-minPrice);
        }
         return maxProfit;
    }

    int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter values: ";
    for(int x=0;x<n;x++){
        cin >> nums[x];
    }
   int ans = maxProfit(nums);
cout << "The profit is: " << ans << endl;

    return 0;

}