#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr, int low , int high){
    int pivot= arr[high];
    int smaller = low-1;
    for(int i=low;i<high;i++){
        if(arr[i]<pivot){
            smaller++;
            swap(arr[smaller],arr[i]);
        }
    }
    swap(arr[smaller+1],arr[high]);
    return smaller+1;
}
void quicksort(vector <int>&arr,int low ,int high){
   if(low<high){
    int pi= partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1, high);
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
    quicksort(arr,0,arr.size()-1);
    cout << "The sorted arr is: ";
    for(int t=0;t<n;t++){
        cout<< arr[t] << " ";
    }
    return 0;

}

