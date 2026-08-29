typedef pair<int,int> pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>> > vp(n+1);
        vector<int> time(n+1, INT_MAX);
        vector<int> visited(n+1, 0);
        for(int i = 0;i<times.size();i++) {
            vp[times[i][0]].push_back({times[i][1],times[i][2] });
        }
        time[k] = 0;
        visited[k] = 1;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push({0, k});

        while(pq.size() != 0) {
            pii curr = pq.top();
            pq.pop();
            visited[curr.second] = 1;
            for(auto adj : vp[curr.second]) {
                if(visited[adj.first] != 1) {
                    time[adj.first] = (time[adj.first] == INT_MAX) ? (curr.first + adj.second) : (min(curr.first + adj.second, time[adj.first]));
                    pq.push({time[adj.first], adj.first});
                }
            }
        }
        int result = -1;
        for(int i = 1;i<n+1;i++) {
            if(time[i] == INT_MAX) return -1;
            result = max(time[i], result);
        }
        return result;
    }
};