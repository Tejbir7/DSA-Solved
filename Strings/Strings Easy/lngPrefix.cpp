#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
   if(strs.empty()) return "";
   sort(strs.begin(),strs.end());
   string first = strs[0];
   string last = strs[strs.size()-1];
   string common;
   int minLength = min(first.size(), last.size());
   for(int i =0;i<minLength;++i){
    if(first[i]!=last[i]) break;
    common+=first[i];
   }
   return common;        
    }

    int main() {


    // Input list of strings
    vector<string> input = {"interview", "internet", "internal", "interval"};

    // Get the result
    string result = longestCommonPrefix(input);

    // Print the result
    cout << "Longest Common Prefix: " << result << endl; 

    return 0;
}
