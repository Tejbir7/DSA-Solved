#include<bits/stdc++.h>
using namespace std;

//  vector<vector<string>> findLaddersUN(string beginWord, string endWord, vector<string>& wordList) {
   
//     //Initialise
//         vector<vector<string>> ans;
//         unordered_set<string> st(wordList.begin(), wordList.end());
//         if(st.find(endWord)==st.end()) return ans;

//         queue<vector<string>> q;
//         q.push({beginWord});
//         st.erase(beginWord);

//         bool found = false;
        
//         while(!q.empty() && !found){
//             int level = q.size();
//             unordered_set<string> levelVisited;

//             for(int i=0; i<level; ++i){
//             auto arr = q.front();
//             q.pop();

//             int n = arr.size();
//             string word = arr[n-1];
//             if(word==endWord) {
//                 ans.push_back(arr);
//                 found = true;
//                 continue;
//             }

//             for(int i=0; i<word.size(); ++i){
//                 char original = word[i];

//                 for(auto j = 'a'; j<= 'z'; ++j){
//                     if(j==original) continue;
//                     word[i] = j;

//                     if(st.find(word)!= st.end()){
//                         levelVisited.insert(word);
//                         auto temp = arr;
//                         temp.push_back(word);
//                         q.push(temp);
//                         temp.clear();
//                     }

//                 }
//                 word[i] = original;
//             }
//         }
//         for(auto &w: levelVisited){
//             st.erase(w);
//         }
//         levelVisited.clear();        
//     }
//     return ans;
// }

// //optimised 
// vector<vector<string>> ans;
// void Dfs(string endWord,string beginWord, unordered_map<string,int> &mp, vector<string> temp){

//     temp.push_back(endWord);
//     if(endWord==beginWord){
//         reverse(temp.begin(), temp.end());
//         ans.push_back(temp);
//         temp.clear();
//         return;
//     }
//     for(int i=0; i<endWord.size(); ++i){
//         char org = endWord[i];
//         string prev = endWord;
//         for(char ch = 'a'; ch<='z'; ++ch){
//             if(ch == org) continue;
//             endWord[i] = ch;
//             if(mp.find(endWord) != mp.end() && mp[endWord] == mp[prev]-1){
//                 Dfs(endWord,beginWord, mp,temp);                
//             }
//         }
//         endWord[i] = org;
//     }

// }


//   vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//     ans.clear();
//     //Step 1: BFS and store in map 
//     unordered_set<string> st(wordList.begin(),wordList.end());
//       if(st.find(endWord) == st.end()) return {};
//     unordered_map<string, int> mp;
//     queue<string>q;

//     q.push(beginWord);
//     st.erase(beginWord);
//     int dist = 1;
//     bool found = false;

//     while(!q.empty() && !found){
//       int level = q.size();
//       unordered_set<string> levelVisited;

//       for(int i=0; i<level; ++i){
//         auto word = q.front(); q.pop();
//        mp[word] = dist;

//           if(word==endWord) {
//                 found = true;
//             }
        

//         for(int i=0; i<word.size(); ++i){
//             char org = word[i];
//             for(char ch='a' ; ch <='z'; ++ch){
//                 if(ch == org) continue;
//                 word[i] = ch;
//                 if(st.find(word)!=st.end()){
//                     q.push(word);
//                     levelVisited.insert(word);
//                 }
//                 word[i] = org;
//             }
//         }
//       }
//       ++dist;
//         for(auto &w: levelVisited){
//             st.erase(w);
//         }
//         levelVisited.clear();   
//     }

//     //dfs
//     vector<string>temp;
//     Dfs(endWord,beginWord,mp,temp);
//     return ans;        
//     }

   

    //more efficient, uses pass by reference 
   
    
    vector<vector<string>> ans;
void dfs(string endWord,string beginWord, unordered_map<string,int> &mp, vector<string> & temp){

    temp.push_back(endWord);
    if(endWord==beginWord){
       vector<string> path = temp;
        reverse(path.begin(), path.end());
        ans.push_back(path);

        temp.pop_back();      // backtrack
        return;
    }
    int sz = endWord.size();
    for(int i=0; i<sz; ++i){
        char org = endWord[i];
        string prev = endWord;
        for(char ch = 'a'; ch<='z'; ++ch){
            if(ch == org) continue;
            endWord[i] = ch;
            if(mp.find(endWord) != mp.end() && mp[endWord] == mp[prev]-1){
                dfs(endWord,beginWord, mp,temp);                
            }
        }
        endWord[i] = org;
        
    }
     temp.pop_back();   
}

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
          ans.clear();
    //Step 1: BFS and store in map 
    unordered_set<string> st(wordList.begin(),wordList.end());
      if(st.find(endWord) == st.end()) return {};
    unordered_map<string, int> mp;
    queue<string>q;

    q.push(beginWord);
    st.erase(beginWord);
    int dist = 1;
    bool found = false;

    while(!q.empty() && !found){
      int level = q.size();
      unordered_set<string> levelVisited;

      for(int i=0; i<level; ++i){
        auto word = q.front(); q.pop();
       mp[word] = dist;

          if(word==endWord) {
                found = true;
            }
        

int sz = word.size();
        for(int i=0; i<sz; ++i){
            char org = word[i];
            for(char ch='a' ; ch <='z'; ++ch){
                if(ch == org) continue;
                word[i] = ch;
                if(st.find(word)!=st.end() &&
   levelVisited.find(word)==levelVisited.end()){
                    q.push(word);
                    levelVisited.insert(word);
                }
                word[i] = org;
            }
        }
      }
      ++dist;
        for(auto &w: levelVisited){
            st.erase(w);
        }
        levelVisited.clear();   
    }

    //dfs
    vector<string>temp;
    dfs(endWord,beginWord,mp,temp);
    return ans;
    }

int main (){
    string beginWord = "aaaaa";
    string endWord = "ggggg";
    vector <string> wordList = {"aaaaa","caaaa","cbaaa","daaaa","dbaaa","eaaaa","ebaaa","faaaa","fbaaa","gaaaa","gbaaa","haaaa","hbaaa","iaaaa","ibaaa","jaaaa","jbaaa","kaaaa","kbaaa","laaaa","lbaaa","maaaa","mbaaa","naaaa","nbaaa","oaaaa","obaaa","paaaa","pbaaa","bbaaa","bbcaa","bbcba","bbdaa","bbdba","bbeaa","bbeba","bbfaa","bbfba","bbgaa","bbgba","bbhaa","bbhba","bbiaa","bbiba","bbjaa","bbjba","bbkaa","bbkba","bblaa","bblba","bbmaa","bbmba","bbnaa","bbnba","bboaa","bboba","bbpaa","bbpba","bbbba","abbba","acbba","dbbba","dcbba","ebbba","ecbba","fbbba","fcbba","gbbba","gcbba","hbbba","hcbba","ibbba","icbba","jbbba","jcbba","kbbba","kcbba","lbbba","lcbba","mbbba","mcbba","nbbba","ncbba","obbba","ocbba","pbbba","pcbba","ccbba","ccaba","ccaca","ccdba","ccdca","cceba","cceca","ccfba","ccfca","ccgba","ccgca","cchba","cchca","cciba","ccica","ccjba","ccjca","cckba","cckca","cclba","cclca","ccmba","ccmca","ccnba","ccnca","ccoba","ccoca","ccpba","ccpca","cccca","accca","adcca","bccca","bdcca","eccca","edcca","fccca","fdcca","gccca","gdcca","hccca","hdcca","iccca","idcca","jccca","jdcca","kccca","kdcca","lccca","ldcca","mccca","mdcca","nccca","ndcca","occca","odcca","pccca","pdcca","ddcca","ddaca","ddada","ddbca","ddbda","ddeca","ddeda","ddfca","ddfda","ddgca","ddgda","ddhca","ddhda","ddica","ddida","ddjca","ddjda","ddkca","ddkda","ddlca","ddlda","ddmca","ddmda","ddnca","ddnda","ddoca","ddoda","ddpca","ddpda","dddda","addda","aedda","bddda","bedda","cddda","cedda","fddda","fedda","gddda","gedda","hddda","hedda","iddda","iedda","jddda","jedda","kddda","kedda","lddda","ledda","mddda","medda","nddda","nedda","oddda","oedda","pddda","pedda","eedda","eeada","eeaea","eebda","eebea","eecda","eecea","eefda","eefea","eegda","eegea","eehda","eehea","eeida","eeiea","eejda","eejea","eekda","eekea","eelda","eelea","eemda","eemea","eenda","eenea","eeoda","eeoea","eepda","eepea","eeeea","ggggg","agggg","ahggg","bgggg","bhggg","cgggg","chggg","dgggg","dhggg","egggg","ehggg","fgggg","fhggg","igggg","ihggg","jgggg","jhggg","kgggg","khggg","lgggg","lhggg","mgggg","mhggg","ngggg","nhggg","ogggg","ohggg","pgggg","phggg","hhggg","hhagg","hhahg","hhbgg","hhbhg","hhcgg","hhchg","hhdgg","hhdhg","hhegg","hhehg","hhfgg","hhfhg","hhigg","hhihg","hhjgg","hhjhg","hhkgg","hhkhg","hhlgg","hhlhg","hhmgg","hhmhg","hhngg","hhnhg","hhogg","hhohg","hhpgg","hhphg","hhhhg","ahhhg","aihhg","bhhhg","bihhg","chhhg","cihhg","dhhhg","dihhg","ehhhg","eihhg","fhhhg","fihhg","ghhhg","gihhg","jhhhg","jihhg","khhhg","kihhg","lhhhg","lihhg","mhhhg","mihhg","nhhhg","nihhg","ohhhg","oihhg","phhhg","pihhg","iihhg","iiahg","iiaig","iibhg","iibig","iichg","iicig","iidhg","iidig","iiehg","iieig","iifhg","iifig","iighg","iigig","iijhg","iijig","iikhg","iikig","iilhg","iilig","iimhg","iimig","iinhg","iinig","iiohg","iioig","iiphg","iipig","iiiig","aiiig","ajiig","biiig","bjiig","ciiig","cjiig","diiig","djiig","eiiig","ejiig","fiiig","fjiig","giiig","gjiig","hiiig","hjiig","kiiig","kjiig","liiig","ljiig","miiig","mjiig","niiig","njiig","oiiig","ojiig","piiig","pjiig","jjiig","jjaig","jjajg","jjbig","jjbjg","jjcig","jjcjg","jjdig","jjdjg","jjeig","jjejg","jjfig","jjfjg","jjgig","jjgjg","jjhig","jjhjg","jjkig","jjkjg","jjlig","jjljg","jjmig","jjmjg","jjnig","jjnjg","jjoig","jjojg","jjpig","jjpjg","jjjjg","ajjjg","akjjg","bjjjg","bkjjg","cjjjg","ckjjg","djjjg","dkjjg","ejjjg","ekjjg","fjjjg","fkjjg","gjjjg","gkjjg","hjjjg","hkjjg","ijjjg","ikjjg","ljjjg","lkjjg","mjjjg","mkjjg","njjjg","nkjjg","ojjjg","okjjg","pjjjg","pkjjg","kkjjg","kkajg","kkakg","kkbjg","kkbkg","kkcjg","kkckg","kkdjg","kkdkg","kkejg","kkekg","kkfjg","kkfkg","kkgjg","kkgkg","kkhjg","kkhkg","kkijg","kkikg","kkljg","kklkg","kkmjg","kkmkg","kknjg","kknkg","kkojg","kkokg","kkpjg","kkpkg","kkkkg","ggggx","gggxx","ggxxx","gxxxx","xxxxx","xxxxy","xxxyy","xxyyy","xyyyy","yyyyy","yyyyw","yyyww","yywww","ywwww","wwwww","wwvww","wvvww","vvvww","vvvwz","avvwz","aavwz","aaawz","aaaaz"};
    vector<vector<string>> paths = findLadders(beginWord,endWord,wordList);
    for (auto &path : paths) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i + 1 < path.size()) cout << " -> ";
    }
    cout << '\n';
}

    return 0;

} 