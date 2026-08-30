class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = -1, minIndex = -1;
        int maxEl = INT_MIN, minEl = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxEl){
                maxEl = nums[i];
                maxIndex = i;
            }

            if(nums[i] < minEl){
                minEl = nums[i];
                minIndex = i;
            }
        }

        cout << minIndex << " " << maxIndex << endl;
        cout << "n = " << nums.size() << endl;
        cout << "mid = " << n / 2 << endl;

        if(n % 2 != 0){
            int mid = n / 2;
            if(minIndex == mid || maxIndex == mid){
                return mid + 1;
            }
        }

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        int op1 = right + 1;
        int op2 = n - left;
        int op3 = (left + 1) + (n - right);

        return min(op1, min(op2, op3));

        // bool minHalf = (minIndex < n / 2);
        // bool maxHalf = (maxIndex < n / 2);

        // cout << minHalf << " " << maxHalf << endl;

        // if(minHalf == maxHalf){
        //     maxIndex = min(maxIndex, n - maxIndex - 1);
        //     minIndex = min(minIndex, n - minIndex - 1);
        //     return max(maxIndex, minIndex) + 1;
        // }
        
        // return (min(minIndex, maxIndex) + 1) + (n - max(minIndex, maxIndex));
    }
};