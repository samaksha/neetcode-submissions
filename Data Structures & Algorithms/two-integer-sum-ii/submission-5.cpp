class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0, R = numbers.size() - 1;

        while(L < R) {
            int sum = numbers[L] + numbers[R];

            if(sum == target) {
                return {L + 1, R + 1};
            }
            else if(sum < target) {
                L++;
            }
            else {
                R--;
            }
        }
    }
};


// 1 3 5 8 9 13, 17


