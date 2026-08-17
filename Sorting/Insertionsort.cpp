#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void insertionsort(vector <int> &arr ){
    int n = arr.size();
    for(int i=1;i<n;i++){  //assuming first el is sorted
        int key = arr[i];
        int j = i-1;
       while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;            
            }
            arr[j+1]=key;
           }
            
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
    insertionsort(arr);
    cout << "The sorted arr is: ";
    for(int t=0;t<n;t++){
        cout<< arr[t] << " ";
    }
    return 0;

}