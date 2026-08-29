class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> m(n);
        for(int i = 0; i < n; i++){
            m[i] = {nums[i], i};
        }

        sort(m.begin(), m.end());
        
        vector<int> result(n);
        int i = 0;

        while(i < n){
            int j = i + 1;
            while(j < n && m[j].first - m[j - 1].first <= limit){
                j++;
            }

            vector<int> indices;
            for(int k = i; k < j; k++){
                indices.push_back(m[k].second);
            }

            sort(indices.begin(), indices.end());
            
            for(int k = 0; k < indices.size(); k++){
                result[indices[k]] = m[i + k].first;
            }

            i = j;
        }
        
        return result;
    }
};