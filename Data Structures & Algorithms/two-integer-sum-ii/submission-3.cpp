class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> indexByValue;

        for(int i = 0 ; i < numbers.size(); i++) {
            int current = numbers[i];
            int need = target - current;

            auto match = indexByValue.find(need);

            if(match != indexByValue.end()) {
                return {match->second, i + 1};
            }
            else {
                indexByValue[current] = i + 1;
            }
        }

        return {};
    }
};
