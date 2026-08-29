class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,vector<int>> indexStore;
        vector<int> result;
        for(int i = 0;i<numbers.size();i++) {
            indexStore[numbers[i]].push_back(i+1);
        }

        for(int i = 0;i < numbers.size() ; i++) {
            int current = numbers[i];
            int needed = target - current;


            if(needed == numbers[i] && indexStore[needed].size() > 1) {
                result.push_back(i+1);
                result.push_back(indexStore[needed][1]);
                break;
            }

            if(indexStore[needed].size() > 0) {
                result.push_back(i+1);
                result.push_back(indexStore[needed][0]);
                break;
            }
        }

        return result;
    }
};
