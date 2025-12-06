

/*
3578. Count Partitions With Max-Min Difference at Most K

You are given a 0-indexed integer array nums and an integer k.
 A partition of the array is called valid if the difference between the maximum and 
 minimum elements in every subarray of the partition is at most k.
*/



class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = nums.size();

        // Sliding window using multiset
        multiset<int> st;
        vector<int> p(n);
        int l = 0;

        for (int r = 0; r < n; r++) {
            st.insert(nums[r]);

            // shrink window until condition max-min ≤ k
            while (!st.empty() && *prev(st.end()) - *st.begin() > k) {
                st.erase(st.find(nums[l]));  // erase only one copy
                l++;
            }
            p[r] = l;   // smallest valid starting index
        }

        vector<int> dp(n);   
        vector<int> psum(n);    // prefix sum of dp

        dp[0] = 1;              // one way to partition 1 element
        psum[0] = 1;

        for (int r = 1; r < n; r++) {
            int l = p[r];

            // We want dp[l] + ... + dp[r-1]
            int rangedp = psum[r - 1];   
            if (l > 0) rangedp -= psum[l - 1];  

            rangedp %= mod;
            if (rangedp < 0) rangedp += mod;

            dp[r] = rangedp;
            psum[r] = (psum[r - 1] + dp[r]) % mod;
            //psum[r] = (dp[0] + dp[1] + ... + dp[r-1]) + dp[r]

        }

        return dp[n - 1];
    }
};
