class Solution {
private:
    struct Cost{
        int leftSize;
        int rightSize;
        multiset<long long> lower;
        multiset<long long> upper;
        long long lowerSum = 0, upperSum = 0;

        Cost(int m){
            leftSize = (m + 1) / 2;
            rightSize = m / 2;
        }

        void balance(){
            while((int)lower.size() > leftSize){
                auto it = prev(lower.end());
                long long val = *it;

                lowerSum -= val;
                lower.erase(it);

                upper.insert(val);
                upperSum += val;
            }

            while((int)lower.size() < leftSize && !upper.empty()){
                auto it = upper.begin();
                long long val = *it;

                upperSum -= val;
                upper.erase(it);

                lower.insert(val);
                lowerSum += val;
            }
        }

        void add(long long x){
            if(lower.empty() || x <= *lower.rbegin()){
                lower.insert(x);
                lowerSum += x;
            }
            else{
                upper.insert(x);
                upperSum += x;
            }

            balance();
        }

        void remove(long long x){
            auto it = lower.find(x);

            if(it != lower.end()){
                lowerSum -= x;
                lower.erase(it);
            }
            else{
                auto it2 = upper.find(x);
                if (it2 != upper.end()){
                    upperSum -= x;
                    upper.erase(it2);
                }
            }

            balance();
        }

        long long getCost(){
            long long median = *lower.rbegin();
            
            return upperSum - lowerSum + (long long)(leftSize - rightSize) * median;
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        if((long long)k * x > n){
            return -1;
        }

        vector<long long> cost(n, 0);
        Cost c(x);

        for(int i = 0; i < n; i++){
            c.add(nums[i]);
            if(i >= x){
                c.remove(nums[i - x]);
            }

            if(i >= x - 1){
                cost[i] = c.getCost();
            }
        }

        long long INF = 1e18;
        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);
        for(int j = 1; j <= k; j++){
            fill(curr.begin(), curr.end(), INF);

            for(int i = j * x; i <= n; i++){
                long long best = curr[i - 1];

                if(prev[i - x] != INF){
                    best = min(best, prev[i - x] + cost[i - 1]);
                }

                curr[i] = best;
            }

            prev = curr;
        }

        return prev[n];
    }
};