#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int secondsmallest(vector <int>&arr){
    int n= arr.size();
    int small = INT_MAX;
    int second_small = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<small){
            second_small = small;
            small = arr[i]; 
        }
        else if(arr[i]<second_small && arr[i]!=small){
            second_small = arr[i];
        }
    }
    return second_small;    
}
int secondlargest(vector <int>&arr){
    int n = arr.size();
    int large = INT_MIN;
    int second_large = INT_MIN;
    for(int i =0; i<n;i++){
        if(arr[i]>large){
            second_large = large;
            large = arr[i];
        }
        else if(arr[i]>second_large && arr[i]!=large){
            second_large = arr[i];
        }
    }
  return second_large;
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
    int ans1 = secondsmallest(arr);
    int ans2 = secondlargest(arr);

    cout << "The second smallest num is: " << ans1 << endl;
    cout << "The second largest num is: " << ans2;
   
    return 0;

}
