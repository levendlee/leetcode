class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;

        int max_len = 1;
        int cur_len = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                max_len = std::max(max_len, ++cur_len);
            } else {
                cur_len = 1;
            }
        }
        return max_len;
    }
};