class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> newDist(n);

        for(int i = 0; i < n; i++){
            newDist[i] = (double)dist[i] / (double)speed[i];
            cout << newDist[i] << " ";
        }

        sort(newDist.begin(), newDist.end());
        int i = 1;

        for(; i < n; i++){
            cout << newDist[i] << " ";
            if(newDist[i] <= (i + 0.00)){
                break;
            }
        }

        return i;

        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // int n = dist.size();

        // for(int i = 0; i < n; i++){
        //     minHeap.push({dist[i], speed[i]});
        // }

        // int count = 0;
        // while(!minHeap.empty()){
        //     auto p = minHeap.top();

        //     if(p.first == 0){
        //         break;
        //     }


        // }

        // return count;
    }
};