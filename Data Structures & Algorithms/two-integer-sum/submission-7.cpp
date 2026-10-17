class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int size = nums.size();
        vector<int> result{};
        unordered_map<int, vector<int>> indexes_by_difference{};

        for (int i = 0; i < size; ++i) {
            int difference = target - nums[i];
            if (auto itr = indexes_by_difference.find(difference); itr != indexes_by_difference.end())  {
                itr->second.push_back(i);
            } else {
                indexes_by_difference.insert({difference, {i}});
            }
        }

        for (const auto& [key, values] : indexes_by_difference) {
            int difference = target - key;
            if (auto itr = indexes_by_difference.find(difference); itr != indexes_by_difference.end()) {
                result.insert(result.begin(), values.begin(), values.end());
                // Prevent adding the same result twice when the key and the difference are the same
                if (difference != key) {
                    result.insert(result.begin(), itr->second.begin(), itr->second.end());
                }
                

                sort(result.begin(), result.end());
                return result;
            }
        }
        
        
        return result;
    }
};
