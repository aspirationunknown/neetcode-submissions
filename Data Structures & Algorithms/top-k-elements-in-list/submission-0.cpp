class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> num_counts;
        for (const auto &n : nums) {
            if (!num_counts.contains(n)) {
                num_counts[n] = 1;
            } else {
                ++num_counts[n];
            }
        }
        std::vector<std::list<int>> buckets;
        buckets.resize(nums.size() + 1);
        for (const auto &[num, count] : num_counts) {
            buckets[count].push_back(num);
        }
        std::vector<int> k_results;
        for (int index = nums.size(); index >= 0 && k > 0; --index) {
            for (const auto &val : buckets[index]) {
                k_results.push_back(val);
                --k;
                if (k == 0) {
                    break;
                }

            }
        }
        return k_results;
    }
};

