class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> sumMap;

        for (int i=0;; ++i) {
            auto it = sumMap.find(target - nums[i]);
            //if difference is found 
            if (it != sumMap.end()) 
                return vector<int> {i, it->second};
            //else store it in map
            sumMap[nums[i]] = i;
        }
    }
};