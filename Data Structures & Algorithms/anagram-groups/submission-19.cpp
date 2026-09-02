class Solution {
public:
    vector<vector<string>> checkAnagram(vector<string> &strs) {
        unordered_map<string, vector<string>> anagrams;
        string current;

        for(int i = 0; i < strs.size() ; i++) {
            current = strs[i];
            vector<int> count(26);
            for(auto s : current) {
                count[s-'a']++;
            }

            string key = to_string(count[0]);
            for(int i = 1; i < 26; i++) {
                key = key + ',' + to_string(count[i]);
            }

            anagrams[key].push_back(current);
        }

        vector<vector<string>> results(anagrams.size());
        int rc = 0;

        for(auto row: anagrams) {
            results[rc++] = (row.second);
        }

        return results;

    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return checkAnagram(strs);
    }
};
// n - lenght
// m - no of entries
//TC - O(n * M) 
//SC - o(M)
