#include<iostream>
#include<vector>
#include<climits>
using namespace std;
 int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    long long sum = 0;
    int lowest = INT_MAX;
    int largest = 0;
    for (int p : piles) {
        sum += p;
        if (p > largest) largest = p;
        if (p < lowest) lowest = p;
    }

    if (h == n) return largest;
    if (h < n) return -1; 

    // safe lower bound: at least 1, or use ceil(avg) to tighten search
    int low = (int)max(1LL, (sum + h - 1) / h); // ceil(sum/h)
    int high = largest;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long k = 0; 

        for (int p : piles) {
            k += (p + mid - 1) / mid;
            if (k > h) break; 
        }

        if (k <= h) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low; // low is minimal feasible speed
}





    int main()
{
    vector<int> v = {312884470};
    int h = 968709470;
    int ans = minEatingSpeed(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}