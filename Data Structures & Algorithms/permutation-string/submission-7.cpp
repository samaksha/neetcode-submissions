class Solution {
public:

    vector<int> getFrequencyArray(string s, int l, int r) {
        vector<int> count(26, 0);
        for(int i = l;i<r;i++) {
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
        if(s1.size() > s2.size()) return false;

        int l = 0, r = s1.size() - 1;
        vector<int> frequencyForS1, frequencyForS2;

        frequencyForS1 = getFrequencyArray(s1, 0, s1.size());
        frequencyForS2 = getFrequencyArray(s2, 0, s1.size());

        while(r < s2.size()) {
            bool output = validSubstring(frequencyForS1, frequencyForS2);
            if(output == true) return output;

            if(r == s2.size() - 1) return false;

            int leftVal = s2[l] - 'a';
            int rightVal = s2[r+1] - 'a';

            frequencyForS2[leftVal]--;
            frequencyForS2[rightVal]++;

            l++;
            r++;
        }

        return false;
    }
};
