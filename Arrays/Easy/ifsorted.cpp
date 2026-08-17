#include<iostream>
#include<vector>
using namespace std;

bool ifsorted(vector <int> &arr){
    int n = arr.size();
    for(int i=0; i<n-1;i++){
        if(arr[i+1]<arr[i]){
            return false;
        }
    }
    return true;
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
    
    cout << (ifsorted(arr) ? "Sorted": "Not Sorted") << endl;
   
    return 0;

}
