#include<iostream>
#include<vector>
using namespace std;

int largestnum(vector <int>&arr){
    int idx=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>arr[idx]){
            idx=i;
        }
    }
return arr[idx];
}
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter values: ";
    for(int x=0;x<n;x++){
        cin >> arr[x];
    }
    int ans = largestnum(arr);
    cout << "The largest num is: " << ans;
   
    return 0;

}
