#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void bubblesort(vector <int> &arr ){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        int didswap =0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap =1;
            }
           }
            if(didswap==0){
                break;
            }
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
    bubblesort(arr);
    cout << "The sorted arr is: ";
    for(int t=0;t<n;t++){
        cout<< arr[t] << " ";
    }
    return 0;

}