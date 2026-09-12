class interval{
    public:
    int left, right, weight, index;

    bool operator<(const interval& other) const {
        if(left != other.left){
            return left < other.left;
        }

        if(right != other.right){
            return right < other.right;
        }

        return index < other.index;
    }
};

class state{
    public:
    long long weight;
    int n;
    int selected[4];

    state(){
        weight = 0;
        n = 0;
    }
};

state better(state &a, state &b){
    if(a.weight > b.weight){
        return a;
    }
    else if(a.weight < b.weight){
        return b;
    }

    for(int i = 0; i < min(a.n, b.n); i++){
        if(a.selected[i] < b.selected[i])
            return a;
        else if(a.selected[i] > b.selected[i])
            return b;
    }

    if(a.n < b.n){
        return a;
    }

    return b;
}

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<interval> temp(n);

        for(int i = 0; i < n; i++){
            temp[i].left = intervals[i][0];
            temp[i].right = intervals[i][1];
            temp[i].weight = intervals[i][2];
            temp[i].index = i;
        }

        sort(temp.begin(), temp.end());
        vector<vector<state>> dp(n + 1, vector<state>(5));

        for(int i = n - 1; i >= 0; i--){
            int j = n;
            int s = i + 1;
            int e = n - 1;

            while(s <= e){
                int mid = s + (e - s) / 2;
                if(temp[mid].left > temp[i].right){
                    j = mid;
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }
            
            for(int k = 1; k <= 4; k++) {
                state skip = dp[i + 1][k];
                state pick = dp[j][k - 1];

                pick.weight += temp[i].weight;
                pick.selected[pick.n++] = temp[i].index;
                sort(pick.selected, pick.selected + pick.n);

                dp[i][k] = better(skip, pick);
            }
        }

        vector<int> result;
        for(int i = 0; i < dp[0][4].n; i++){
            result.push_back(dp[0][4].selected[i]);
        }
        
        return result;
    }
};