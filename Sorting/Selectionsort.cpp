#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Selectionsort(vector<int>& arr){     
    int n= arr.size();
    for(int i=0;i<n-1;i++){
        int minidx=i;
         for(int j=i+1;j<n;j++){
            //finding minidx
            if(arr[j]<arr[minidx]){
                minidx=j;
            }            
         }
         if(minidx!=i){
         swap(arr[minidx],arr[i]);
         }
    }
}

int main(){
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    Selectionsort(arr);
     for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}