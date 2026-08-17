#include<bits/stdc++.h>
using namespace std;
void generate(string temp, vector<int>&ans, int low, int high){
     int num = stoi(temp);
   if(num > high) return;

    if(num>=low && num<=high) ans.push_back(num);

    int n = temp.size();
    char last = temp[n-1];
    if(last=='9') return;

    last = last+1;
    temp.push_back(last);
    generate(temp,ans, low, high);
}

vector<int> sequentialDigits(int low, int high) {
    vector<int>ans;

    for( char i= '1'; i <= '9'; ++i){
        string temp(1, i);
        generate(temp,ans, low, high);
    }
     sort(ans.begin(), ans.end());
    return ans;
    }

    //Sliding Window
      vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> ans;
        
        int lowLen = to_string(low).length();
        int highLen = to_string(high).length();
        
        // Generate numbers by length first, ensuring they are sorted
        for (int len = lowLen; len <= highLen; ++len) {
            
            // Slide a window of size 'len' across "123456789"
            for (int i = 0; i <= 9 - len; ++i) {
                string sub = digits.substr(i, len);
                int num = stoi(sub);
                
                // Add to answer if it falls within the [low, high] range
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        
        return ans;
    }