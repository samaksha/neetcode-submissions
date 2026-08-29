class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> duplicates;
        bool result = false;
        for(int i = 0 ; i < nums.size() ; i++) {
            int num = nums[i];
            duplicates[num]++;
            if(duplicates[num]>1) {
                result = true;
                break;
            }
        }

        return result;
    }
};