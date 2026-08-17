/* =========================================================
   UNIVERSAL DSA TEMPLATE (MSVC + HackerRank + IBM SAFE)
   Author: Tejbir
   Purpose: Pattern recall, not blind copy
   ========================================================= */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <climits>
#include <cstring>
#include <numeric>
using namespace std;

/* =========================================================
   INPUT / OUTPUT FAST IO
   ========================================================= */
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


/* =========================================================
   SLIDING WINDOW TEMPLATES
   ========================================================= */

// 1) Longest window with condition (e.g., <= k bad elements)
void slidingWindowAtMostK() {
    int l = 0;
    for (int r = 0; r < n; r++) {
        // update using r

        while (/* window invalid */) {
            // shrink using l
            l++;
        }

        ans = max(ans, r - l + 1);
    }
}

// 2) Longest substring without repeat
void slidingWindowUnique() {
    vector<int> last(256, -1);
    int l = 0;
    for (int r = 0; r < n; r++) {
        if (last[s[r]] >= l)
            l = last[s[r]] + 1;
        last[s[r]] = r;
        ans = max(ans, r - l + 1);
    }
}

/* =========================================================
   HASH MAP / FREQUENCY
   ========================================================= */

// Frequency count
void freqMap() {
    unordered_map<int, int> freq;
    for (int x : arr) freq[x]++;
}

// Last seen index (string / array)
void lastSeenIndex() {
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.count(s[i])) {
            // seen before
        }
        mp[s[i]] = i;
    }
}

/* =========================================================
   PREFIX SUM
   ========================================================= */

// Subarray sum = k
void prefixSumK() {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    for (int x : arr) {
        sum += x;
        if (mp.count(sum - k)) {
            // found
        }
        mp[sum]++;
    }
}

/* =========================================================
   BINARY SEARCH
   ========================================================= */

// Classic binary search
int binarySearch(vector<int>& a, int target) {
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == target) return mid;
        else if (a[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// Binary search on answer
bool canDo(int mid) {
    return true; // feasibility check
}

void binarySearchAnswer() {
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (canDo(mid)) r = mid;
        else l = mid + 1;
    }
}

/* =========================================================
   LINKED LIST
   ========================================================= */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Reverse linked list
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *cur = head;
    while (cur) {
        ListNode* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

/* =========================================================
   STACK / MONOTONIC STACK
   ========================================================= */

void monotonicStack() {
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        st.push(i);
    }
}

/* =========================================================
   QUEUE / BFS
   ========================================================= */

void bfsTemplate(int src) {
    queue<int> q;
    vector<int> vis(n, 0);
    q.push(src);
    vis[src] = 1;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int nei : adj[node]) {
            if (!vis[nei]) {
                vis[nei] = 1;
                q.push(nei);
            }
        }
    }
}

/* =========================================================
   DFS / RECURSION
   ========================================================= */

void dfs(int node, vector<int>& vis) {
    vis[node] = 1;
    for (int nei : adj[node]) {
        if (!vis[nei]) dfs(nei, vis);
    }
}

/* =========================================================
   BACKTRACKING
   ========================================================= */

void backtrack(int idx) {
    if (idx == n) {
        // solution found
        return;
    }
    for (int i = 0; i < n; i++) {
        // choose
        backtrack(idx + 1);
        // undo
    }
}

/* =========================================================
   DYNAMIC PROGRAMMING
   ========================================================= */

// 1D DP
void dp1D() {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
    }
}

// 2D DP
void dp2D() {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
}

/* =========================================================
   UNION FIND (DSU)
   ========================================================= */

struct DSU {
    vector<int> parent, rankv;
    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rankv[a] < rankv[b]) swap(a, b);
            parent[b] = a;
            if (rankv[a] == rankv[b]) rankv[a]++;
        }
    }
};

/* =========================================================
   MATH / EDGE SAFETY
   ========================================================= */

void mathTips() {
    int mn = INT_MIN;
    int mx = INT_MAX;
    long long safeAbs = llabs((long long)mn);
}

/* =========================================================
   SOLVE FUNCTION (ONLY THIS GOES IN TEST)
   ========================================================= */

int solve() {
    // Read input
    // Apply one pattern
    // Return answer
    return 0;
}

/* =========================================================
   MAIN
   ========================================================= */

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fastIO();
    cout << solve() << "\n";
    return 0;
}
