class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> vec;
        int i=0, length = 0;
        for (char x:s) {
            auto it = std::find(vec.begin()+i, vec.end(), x);
            if (it != vec.end()) {
                //if subVec.size() > length
                if (vec.size()-i > length) length = vec.size()-i;
                i = it - vec.begin() + 1;
            }
                vec.push_back(x);
        }
        //end case scencerio 
        if (vec.size()-i > length) length = vec.size()-i;
        return length;
    }
};