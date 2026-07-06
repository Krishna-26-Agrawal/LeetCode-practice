class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), count = 0;
        vector<int> visited(n, 0);

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1] && !visited[i]){
                    visited[i] = 1;
                    count++;
                }
                else if(intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1] && !visited[j]){
                    visited[j] = 1;
                    count++;
                }
            }
        }

        return n - count;
    }
};