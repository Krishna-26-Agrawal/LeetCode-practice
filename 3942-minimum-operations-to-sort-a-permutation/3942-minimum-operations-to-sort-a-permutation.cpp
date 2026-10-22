class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                pos = i;
                break;
            }
        }

        bool inc = true;
        bool dec = true;
        for(int i = 0; i < n; i++){
            if(nums[(pos + i) % n] != i)
                inc = false;

            if(nums[(pos - i + n) % n] != i)
                dec = false;
        }

        if(!inc && !dec)
            return -1;

        int ans = INT_MAX;
        if(inc){
            int rot = pos;
            int rev = ((n - pos) % n) + 2;
            ans = min(ans, min(rot, rev));
        }

        if(dec){
            int revRot = 1 + (n - 1 - pos);
            int rotRev = ((pos + 1) % n) + 1;
            ans = min(ans, min(rotRev, revRot));
        }

        return ans;
    }
};