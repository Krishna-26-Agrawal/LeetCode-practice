class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int j = 0;
        int n = nums.size();
        set<int> s;
        while(j < n){
            if((nums[j] % k) == 0){
                s.insert(nums[j]);
                // swap(nums[i], nums[j]);
                // i++;
            }

            j++;
        }

        set<int>::iterator it = s.begin();
        int sz = s.size();

        for(int x = 0; x < sz; x++){
            if(*it != k * (x + 1)){
                return k * (x + 1);
            }

            it++;
        }

        return k * (sz + 1);

        // cout << "i = " << i << endl;

        // sort(nums.begin(), nums.begin() + i);

        // for(int i : nums){
        //     cout << i << " ";
        // }
        // cout << endl;

        // vector<int> temp(i);

        // for(int x = 0; x < i; x++){
        //     if(nums[x])
        //     // cout << nums[x] << " " << k * (x + 1) << endl;
        //     // if(nums[x] != k * (x + 1)){
        //     //     return k * (x + 1);
        //     // }
        //     else{
        //         temp[x] = nums[x];
        //     }
        // }

        // return k * (i + 1);
    }
};