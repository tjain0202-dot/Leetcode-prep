class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int w = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] != val) {
                nums[w] = nums[r];
                w++;
            }
        }
        return w;
    }
};