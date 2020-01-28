class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int n = nums.size();
        int lo = 0, hi = n - 1, mid, start = -1, end = -1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else if (mid == 0 || nums[mid-1] < target) {
                start = mid;
                break;
            } else {
                hi = mid - 1;
            }
        }

        lo = 0, hi = n - 1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else if (mid == n - 1 || nums[mid+1] > target) {
                end = mid;
                break;
            } else {
                lo = mid + 1;
            }
        }

        return {start, end};
    }
};