#include<iostream>
#include<vector>
#include<string>

#include<algorithm>
using namespace std;
  int numberOfSubstrings(string s) {
           int n = s.size();
    if(!n) return 0;
    int no = 0;
    for(int i=0;i<n;++i){
        bool a = false, b= false, c= false;
        for(int j=i;j<n;++j){
           if (s[j] == 'a') a = true;
            else if (s[j] == 'b') b = true;
            else if (s[j] == 'c') c = true;

            if (a && b && c) {
                no += (n - j);
                break;
            }
        }
    }
        return no;
    }
    int optimal(string s){
        int n = s.size();
        if(!n) return 0;
        int l = 0, r=0, no=0;
        int hash[3] ={0};
        while(r<n){
             ++hash[s[r]-'a'];
            while(hash[0]>0 && hash[1]>0 && hash[2]>0){
            no+= (n-r);
            --hash[s[l]-'a'];
            ++l;
            }       
           
            ++r;
        }
        return no;
    }

    int best(string s){
        int n = s.size();
        if(!n) return 0;
        int lastSeen[3] = {-1,-1,-1};
        int no =0;
        for(int r=0;r<n;++r){
            lastSeen[s[r]-'a'] = r;
            if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
                int mn = min({lastSeen[0],lastSeen[1], lastSeen[2]});
                no+=(1+mn);
              
            }
        }
        return no;
    }
    int main(){
        string s = "abcabc";
        int maxxi = best(s);
        cout << maxxi;
        return 0;
    }