class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = min(cost1, costBoth);
        long long c2 = min(cost2, costBoth);
        long long cb = min(costBoth, cost1 + cost2);

        long long ans = (min(need1, need2) * 1LL) * cb;

        if(need1 > need2){
            ans += ((need1 - need2) * 1LL) * c1;
        }
        else{
            ans += ((need2 - need1) * 1LL) * c2;
        }

        return ans;
    }
};