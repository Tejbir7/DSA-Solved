#include<iostream>
#include<vector>
using namespace std;
 int findKthPositive(vector<int>& arr, int k) {
  int n = arr.size();
  int i = 0,j=1,step=0,ans=0;
  while(j<=1000){
    if(j==arr[i]){
        ++i,++j;
    }else{
        ans = j;
        ++j,++step;
    }
    if(step>=k) break;
  }
  return ans;

}

int main()
{
    vector<int> vec = {5,6,7,8,9};
    int k = 9;
    int ans = findKthPositive(vec, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}