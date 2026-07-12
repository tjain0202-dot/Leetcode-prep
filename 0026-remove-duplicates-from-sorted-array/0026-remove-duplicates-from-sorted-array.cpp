class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        
        int w = 0;
        int r = 1;
        
        while (r < size) {
            if (nums[w] == nums[r]) {
                r++;
            } else {
                nums[w + 1] = nums[r];
                w++;
                r++;
            }
        }
        return w + 1;
    }
};
