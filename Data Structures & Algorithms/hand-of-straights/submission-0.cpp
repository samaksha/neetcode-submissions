class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;
        map<int,int> mp;
        for(int i = 0;i<hand.size();i++) {
            mp[hand[i]]++;
        }
        int start = 0;
        for(int i = 0;i<hand.size();) {
            for(auto adj:mp) {
                if(adj.second > 0){
                    start = adj.first;
                    i++;
                    mp[start]--;
                    break;
                }
            }
            cout<<start<<endl;
            int loop = groupSize-1;
            while(loop--) {
                if(mp[start+1] > 0) {
                    mp[start+1]--;
                    start = start+1;
                    i++;
                    cout<<start<<endl;
                }
                else { return false; };
            }
        }
        return true;
    }
};
