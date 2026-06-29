class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> newDist(n);

        for(int i = 0; i < n; i++){
            newDist[i] = (double)dist[i] / (double)speed[i];
        }

        sort(newDist.begin(), newDist.end());
        int i = 1;

        for(; i < n; i++){
            if(newDist[i] <= i) break;
        }

        return i;
    }
};