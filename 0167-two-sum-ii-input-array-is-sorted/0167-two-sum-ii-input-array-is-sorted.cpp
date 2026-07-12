class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        
        // Using a pair to store the internal tracking (as requested)
        pair<int, int> indices = make_pair(-1, -1);
        
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            
            if (sum == target) {
                // Convert 0-index to 1-index inside the pair
                indices = make_pair(l + 1, r + 1);
                break; 
            }
            else if (sum < target) {
                l++;
            }
            else {
                r--;
            }
        }
        return {indices.first, indices.second};
    }
};