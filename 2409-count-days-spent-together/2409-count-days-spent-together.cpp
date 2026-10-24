class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> prefixSum = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        int aliceArrive = prefixSum[stoi(arriveAlice.substr(0, 2)) - 1] + stoi(arriveAlice.substr(3));

        int aliceLeave = prefixSum[stoi(leaveAlice.substr(0, 2)) - 1] + stoi(leaveAlice.substr(3));

        int bobArrive = prefixSum[stoi(arriveBob.substr(0, 2)) - 1] + stoi(arriveBob.substr(3));

        int bobLeave = prefixSum[stoi(leaveBob.substr(0, 2)) - 1] + stoi(leaveBob.substr(3));

        cout << aliceArrive << " " << aliceLeave << " " << bobArrive << " " << bobLeave << endl;

        int start = max(aliceArrive, bobArrive);
        int end = min(aliceLeave, bobLeave);

        if(end >= start){
            return end - start + 1;
        }

        return 0;
    }
};