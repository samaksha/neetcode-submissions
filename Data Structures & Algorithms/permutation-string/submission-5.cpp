class Solution {
public:

    vector<int> getFrequencyArray(string s) {
        vector<int> count(26, 0);
        for(int i = 0;i<s.size();i++) {
            count[s[i]-'a']++;
        }
        return count;
    }

    bool validSubstring(vector<int> frequency1, vector<int> frequency2) {
        for(int i = 0;i<26;i++) {
            if(frequency1[i] != frequency2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int l = 0, r = 0;
        bool output;
        vector<int> frequencyForS1, frequencyForS2;

        frequencyForS1 = getFrequencyArray(s1);

        while(l < s2.size()) {
            frequencyForS2 = vector<int> (26, 0);

            for(r = l; r < s2.size() ; r++) {
                int val = s2[r] - 'a';
                frequencyForS2[val]++;
                if(frequencyForS2[val] > frequencyForS1[val]){
                    if(frequencyForS1[val] == 0) r++;
                    break;
                }
                else {
                    bool output = validSubstring(frequencyForS1, frequencyForS2);
                    if(output) return true;
                }
            }

            l++;
        }

        return false;
    }
};
