#include<bits/stdc++.h>
using namespace std;
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return 0;

        q.push({beginWord,1});
        st.erase(beginWord);

        set<char>alphabets;
        for(auto it: wordList){
            for(auto i: it){
                alphabets.insert(i);
            }
        }

        while(!q.empty()){
            auto [word,steps] = q.front();
            q.pop();

            if(word==endWord) return steps;

            for(int i=0; i<word.size(); ++i){
                char original = word[i];

                for(auto j: alphabets){
                    if(j == original) continue;
                    word[i] = j;

                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }