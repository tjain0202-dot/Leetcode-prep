class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int l = 0;
        int size = nums.size();
        int minlength = size + 1;
        for (int r = 0; r < size; r++) {
            sum += nums[r];
            while (sum >= target) {
                minlength = min(minlength, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        if (minlength == size + 1) {
            return 0;
        }
        return minlength;
    }
};
