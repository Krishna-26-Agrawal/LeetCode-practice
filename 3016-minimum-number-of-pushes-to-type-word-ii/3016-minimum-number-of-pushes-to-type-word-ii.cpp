class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        if(a.first == b.first){
            return a.second < b.second;
        }

        return a.first > b.first;
    }

    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char c : word){
            freq[c - 'a']++;
        }

        vector<pair<int, int>> count;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                count.push_back({freq[i], i});
            }
        }

        sort(count.begin(), count.end(), comp);

        int cnt = 0, ans = 0, index = 1;
        for(auto p : count){
            // cout << (char)(p.second + 'a') << endl;
            cnt++;

            int prod = p.first * index;
            // cout << "index = " << index << endl;
            ans += prod;

            if(cnt == 8){
                cnt = 0;
                index++;
            }            
        }

        return ans;
    }
};