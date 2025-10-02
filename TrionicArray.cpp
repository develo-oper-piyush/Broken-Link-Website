class Solution {
public:
        bool isTrionic(vector<int>& nums) {
        int p = -1, q = -1, n = nums.size();
        if (n < 3) return false;  // Must have at least 3 elements to form 3 segments

        // Find first drop, but ensure there's prior increase
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                p = i;
                break;
            }
        }
        // If no drop or drop is at first index, invalid
        if (p <= 0) return false;

        // From p, find next increase, ensuring full decrease in between
        for (int i = p; i < n - 1; i++) {
            if (nums[i] <= nums[i + 1]) {
                q = i;
                break;
            }
        }
        // If no increase after drop, or increase is immediately (no decrease segment), invalid
        if (q <= p) return false;

        // Check last segment strictly increasing to end
        for (int i = q; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) return false;
        }

        // All checks passed
        return true;
    }
};
