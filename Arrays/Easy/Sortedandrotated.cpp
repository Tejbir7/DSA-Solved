#include<iostream>
#include<vector>
using namespace std;
bool check(vector <int> &arr){
    int n = arr.size();
    if (n <= 1) return true; 
    int drops = 0;
    for(int i=0;i<n;++i){
        if(arr[i]>arr[(i+1)%n]){
            ++drops;
            if(drops>1) return false;
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
    
    cout << (check(arr) ? "Sorted": "Not Sorted") << endl;
   
    return 0;

}
