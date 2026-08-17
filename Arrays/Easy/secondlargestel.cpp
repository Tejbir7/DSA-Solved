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
int secondlargest(vector <int>&arr, int val){
     int idx=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>arr[idx] && arr[i]<val){
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
    int ans1 = largestnum(arr);
    int ans2 = secondlargest(arr,ans1);

    cout << "The second largest num is: " << ans2;
   
    return 0;

}
