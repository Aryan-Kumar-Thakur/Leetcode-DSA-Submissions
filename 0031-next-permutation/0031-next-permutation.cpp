class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        int j = n - 1;
        while (j > 0) {
            if (nums[j] > nums[j - 1]) {
                ind = j - 1;
                break;
            }
            j--;
        }
        int mini = INT_MAX;
        int minind = 0;
        if (ind != -1) {
            for (int i = ind + 1; i < n; i++) {
                if (nums[i] > nums[ind] && nums[i] <= mini) {
                    mini = nums[i];
                    minind = i;
                }
            }
            swap(nums[minind], nums[ind]);
        }
        reverse(nums.begin() + ind + 1, nums.end());
    }
};