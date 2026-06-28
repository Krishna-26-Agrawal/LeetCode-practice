class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        // cout << "n = " << n << endl;
        // int ifCount = 0, elseCount = 0;

        // set<int> s;

        sort(arr.begin(), arr.end());

        arr[0] = 1;

        for(int i = 1; i < n; i++){
            // s.insert(arr[i]);
            if(arr[i] > arr[i - 1]){
                arr[i] = arr[i - 1] + 1;
                // ifCount++;
            }
            // else{
            //     elseCount++;
            // }
            // arr[i] = (arr[i] >= (i + 1)) ? i + 1 : arr[i];
        }

        // cout << "Count: " << ifCount << " " << elseCount << endl;

        // cout << "PRINTING" << endl;

        // for(int i : s){
        //     cout << i << " ";
        // }

        // cout << endl << "OVER" << endl;

        int maxEl = INT_MIN;
        for(int i : arr){
            maxEl = max(maxEl, i);
        }

        return maxEl;
    }
};