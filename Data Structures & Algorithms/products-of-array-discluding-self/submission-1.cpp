class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int left = 1, right = 1;
        for(int i = 0; i<nums.size(); i++ ) {
            output.push_back(1);
        }

        for(int i = 0;i<nums.size();i++) {
            output[i] = output[i] * left;
            left = left*nums[i];
        }

        for(int i = nums.size()-1;i >= 0 ; i--) {
            output[i] = output[i] * right;
            right = right * nums[i];
        }

        return output;
    }
};


// 1 2 4 6
// 1 1 2 8
// 48  24  6  1 

// 1 2 6 1
// = 48 24 12 8


