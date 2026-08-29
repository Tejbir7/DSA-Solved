#include<bits/stdc++.h>
using namespace std;
int n, k;

void dfs(int wt, int rem, vector<int> & curr){
   if(wt==n){
    if(rem % wt != 0){
       return;
    }
     curr.push_back(rem/wt);
    for(int i=0; i<n; ++i){
        cout << curr[i] << " ";
    }

    cout << '\n';
    curr.pop_back();
    return ;
   }

    for(int j=0; j*wt <=rem; ++j){

        curr.push_back(j);

        dfs(wt+1, rem- j*wt, curr);

        curr.pop_back();
    }

   
}
int main(){
    cin >> n >> k;
        
    vector<int> current;
    dfs(1,k,current);
    return 0;
   
}