#include<iostream>
#include <string>
#include <vector> 
using namespace std;
bool isAnagram(string& s, string& t) { 
if (s.size() != t.size()) return false;
int freq[26] = {0}; 
for (size_t i = 0; i < s.size(); ++i) { 
  ++freq[s[i] - 'a']; 
  --freq[t[i] - 'a']; 
} 
for (int cnt : freq) if (cnt != 0) return false; return true; 
}
int main()
{
  string Str1 = "INTEGER";
  string Str2 = "TEGERNI";
  if(isAnagram(Str1, Str2))
  cout << "True" << endl;
  else
  cout<<"False"<<endl;
  return 0;
}