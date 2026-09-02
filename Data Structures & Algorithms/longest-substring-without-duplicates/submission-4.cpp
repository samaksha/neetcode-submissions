class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), result = 0;
        vector<int> LS(n, 0);
        unordered_map<char, int> lastIndex;

        for(int i = 0; i < s.size(); i++) {
            char current = s[i];

            if(lastIndex.find(current) == lastIndex.end()) {
                LS[i] = (i > 0) ? LS[i-1] + 1: 1;
            }
            else {
                int length = i - lastIndex[current];
                LS[i] = min(LS[i-1]+1, length);
            }
            
            lastIndex[current] = i;
            
            result = max(result, LS[i]);
        }

        return result;
    }
};
