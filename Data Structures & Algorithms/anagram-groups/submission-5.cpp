class Solution {
public:
// 100*100*100
    vector<vector<string>> checkAnagram(vector<string> &strs) {
        map<string, vector<int>> anagrams;
        string current, sorted;
        for(int i = 0; i < strs.size() ; i++) {
            current = strs[i];
            sort(current.begin(), current.end());

            anagrams[current].push_back(i);
        }

        vector<vector<string>> results(anagrams.size(), vector<string> (0));
        int rc = 0;

        for(auto it : anagrams) {
            vector<int> row = it.second;

            for(int j = 0;j < row.size();j++) {
                results[rc].push_back(strs[row[j]]);
            }
            rc++;
        }

        return results;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return checkAnagram(strs);
    }
};

//TC - O(n * M) 
//SC - o(M)
