#include<bits/stdc++.h>
using namespace std;
//Mathematical variant
//Proof:
// Since the number of piles is even, Alice can force herself to take all even-indexed or all odd-indexed piles by choosing the appropriate endpoint on her first move and maintaining that parity.
// Let their sums be E and O; since the total E + O is odd, E != O, so one parity has strictly more stones.
// Alice chooses the parity with the larger sum, so she can guarantee more stones than Bob → return true.
class Solution {
public:
    bool stoneGame(vector<int>& nums) { return true; }
};

//Dp
