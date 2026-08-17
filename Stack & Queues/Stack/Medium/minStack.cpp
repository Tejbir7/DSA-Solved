#include<iostream>
#include<utility>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class MinStack {
    private: 
    vector<int> sorted;
    stack<int> unsorted;

public:
    MinStack() {
       
               
    }
    
    void push(int val) {
        unsorted.push(val);
       
        //sorted
        sorted.push_back(val);
        int i = sorted.size() - 1;
        int j = i-1;
        int key = sorted[i];
        while(j >= 0 && sorted[j] > key){
            sorted[j+1] = sorted[j];
            j--;
        }
        sorted[j+1] = key;

    }
    
    void pop() {

      int x= unsorted.top();
      unsorted.pop();

      for(int i=0; i<sorted.size(); ++i){
        if(sorted[i]==x){
            sorted.erase(sorted.begin()+i);
            break;
        }
      }
        
    }
    
    int top() {
        return unsorted.top();
        
    }
    
    int getMin() {
        return sorted[0];
        
    }
};

//Minor improvement
class MinStack {
    private: 
    vector<int> sorted;
    stack<int> unsorted;

public:
    MinStack() {
       
               
    }
    
    void push(int val) {
        unsorted.push(val);
       
        //sorted
        sorted.push_back(val);

    }
    
    void pop() {

      
      unsorted.pop();
      sorted.pop_back();
        
    }
    
    int top() {
        return unsorted.top();
        
    }
    
    int getMin() {
        vector<int> temp = sorted;
        sort(temp.begin(), temp.end());
        return temp[0];

        
    }
};
//better 
class MinStack {
    private:
    stack<pair<int,int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }else{
           int mini = min(st.top().second, val);
           st.push({val,mini});
        }
    }
    
    void pop() {
        st.pop();
        
    }
    
    int top() {
        return st.top().first;
        
    }
    
    int getMin() {
        return st.top().second;
        
    }
};

//best
class MinStack {
    private:
    stack<long long> st;
    long long mini = INT_MAX;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }else if( mini <= val){
            st.push(val);
        }else{
            long long temp = 2LL * val;
            temp = temp - mini;
            st.push(temp);
            mini = val;
        }
        
    }
    
    void pop() {
        if(mini<= st.top()) st.pop();
        else{
            long long x = st.top();
            st.pop();
            mini = 2*mini - x;
        }
        
    }
    
    int top() {
        if(mini<=st.top()) return st.top();
        else return mini;
    }
    
    int getMin() {
        return mini;
        
    }
};