#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<vector>
using namespace std;
/*  int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if (n==0) return 0;
        sort(nums.begin(),nums.end());
        int longest=1,curr =1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]==nums[i-1]+1){
                ++curr;
            }else{
                longest = max(longest,curr);
                curr =1;

            }
        }
            return max(longest,curr);
    }
*/
//BETTER APPROACH
  int longestConsecutive(vector<int>& nums) {
      //  unordered_set <int> s(nums.begin(),nums.end());
         unordered_set<int> s;
    s.reserve(nums.size() * 2);     // avoid multiple rehashes
    s.max_load_factor(0.7f);        // better load factor
    for (int x : nums) s.insert(x);
        int longest = 0;

        for(int num : s){
            if(!s.count(num-1)){
                int curr = num,streak =1;
                while(s.count(curr+1)){
                    ++curr;
                    ++streak;
                }
                longest = max(longest,streak);
            }
        }
        return longest;
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
   int ans = longestConsecutive(nums);
cout << "The required ans is: " << ans << endl;

    return 0;

}