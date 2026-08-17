#include<iostream>
#include<vector>
using namespace std;
int main(){
        int n;
        cout<<"Enter n: ";
        cin >>n;

        vector<int> arr(n);
        cout << "Enter array elements: ";
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        //precompute
        int hashsize;
        cout << "Enter max element you wanna store in array: ";
        cin >> hashsize;

        vector<int> hash(hashsize+1,0); // dynamically sized 

    
         for(int i=0;i<n;i++){
              if (arr[i] >= 0 && arr[i] < hashsize+1) {
            hash[arr[i]] += 1;
        } else {
            cout << "Warning: Element " << arr[i] << " out of hash range.\n";
        }
        }

        int q;
        cout <<"Enter no of entries: ";
        cin >> q;

        while(q--){
            int number;
            cin >> number;
            //fetch
             if (number >= 0 && number < hashsize+1)
            cout << hash[number] << endl;
        else
            cout << "Out of range\n";
        }
         return 0;
        }
       
