class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> visited(2048, 0);
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                visited[nums[i] ^ nums[j]] = 1;
            }
        }

        unordered_set<int> s;

        for(int i = 0; i < 2048; i++){
            if(visited[i]){
                for(int c : nums){
                    s.insert(c ^ i);
                }
            }
        }

        return s.size();
    }
};