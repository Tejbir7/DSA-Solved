#include<iostream>
#include<string>
using namespace std;

 string reverseWords(string s) {
    int n = s.length();
    int left = 0;
    string temp,ans;
    while(left<=n-1){
        char ch = s[left];
        if(ch!=' '){
            temp+=ch;
        }
        else if(ch == ' ' && temp!=""){
            if(ans!=""){
                ans=temp+' '+ans;
            }else ans= temp;
            temp="";
        }
        ++left;
    }
   if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    return ans;
    }

    string reverseWords(string s) {
    int n = s.size();
    string temp;
    vector<string> words;

    for (int i = 0; i < n; ++i) {
        if (s[i] != ' ') temp += s[i];
        else if (!temp.empty()) {
            words.push_back(temp);
            temp.clear();
        }
    }
    if (!temp.empty()) words.push_back(temp);

    string ans;
    ans.reserve(s.size()); // avoid reallocation

    for (int i = words.size() - 1; i >= 0; --i) {
        ans += words[i];
        if (i) ans += ' ';
    }
    return ans;
}

    int main()
{
    string st="  TUF is    great for interview preparation";
    cout<<"Before reversing words: "<<endl;
    cout<<st<<endl;
    cout<<"After reversing words: "<<endl;
    cout<<reverseWords(st);
    return 0;
}