class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.size() < 2) {
            return false;
        }

        std::unordered_set<int> num_set; 
        for (const auto &n : nums) {
            if (auto p = num_set.insert(n); !p.second) {
                return true;
            }
        }
        return false;
    }
};