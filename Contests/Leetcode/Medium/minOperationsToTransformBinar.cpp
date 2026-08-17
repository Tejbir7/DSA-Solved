#include<bits/stdc++.h>
using namespace std; 
 int minOperations(string s1, string s2) {
    int n = s1.size();  
    if(n==1 && s1[0] == '1' && s2[0] == '0') return -1;

    int count = 0;
    for(int idx=0; idx<n; ++idx){
        if(s1[idx]==s2[idx]) continue;

        //case1: simple
        if(s1[idx]== '0') {
            ++count;
            s1[idx] = '1';
        }

        else if(s1[idx] == '1'){  //ie s2[i] = 0
            int nextIdx = idx+1;
            if(nextIdx<=n-1 ){
                if(s1[nextIdx] == '1'){
                ++count;
                s1[idx] = '0';
                s1[idx+1] = '0';
                }else{
                     count+=2;
                     s1[idx] = '0';
                }
            } 

            else if(nextIdx == n){ //Last element, so check prev
               // s1[idx] = '0';  //change
                // if(s1[idx-1] == '1'){
                //     ++count;
                // }
                // if(s1[idx-1] == '0'){
                //     count+=2;
                // }
                // idx = idx-2; //go to prev to check discrepancy 
                count+=2;
                s1[idx] = '0';
            }
            else return -1;
        }
    }

    return count;
    }

     
//Cleaned up approach:
int minOperations(string s1, string s2) {
    int n = s1.size();  
    if (n == 1 && s1[0] == '1' && s2[0] == '0') return -1;

    int count = 0;
    for (int idx = 0; idx < n; ++idx) {
        if (s1[idx] == s2[idx]) continue;

        // Case 1: Simple: 0 to 1
        if (s1[idx] == '0') {
            ++count;
            s1[idx] = '1';
        } 
        // Case 2: Changing '1' to '0'
        else { 
            // If there's a next element and it's also a '1', flip both for cost 1
            if (idx + 1 < n && s1[idx + 1] == '1') {
                ++count;
                s1[idx] = '0';
                s1[idx + 1] = '0';
            } else {
                //last element or s1[idx+1] == '0'
                count += 2;
                s1[idx] = '0';
            }
        }
    }
    return count;
}