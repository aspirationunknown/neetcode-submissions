class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> results{};
        size_t size = nums.size();

        if (size == 3 && (nums[0] + nums[1] + nums[2]) == 0) {
            results.push_back(nums);
            return results;
        }
        size_t i{};
        size_t j{};
        size_t k{};
        for (;i < size - 2; ++i) {
            if(nums[i] > 0){
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            j = i + 1;
            k = size - 1;
            while (j < k) {
                if (-nums[i] == nums[j] + nums[k]) {
                    std::vector<int> triple{nums[i], nums[j], nums[k]};
                    results.push_back(triple);
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                } else if (nums[j] + nums[k] > -nums[i]) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        
        return results;
    }
};
