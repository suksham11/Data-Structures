class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currtime = 0;
        long long totalwaitingtime = 0;

        for(const auto&customer : customers){
           int arrivaltime = customer[0];
           int preperationtime = customer[1];
        

        if(currtime < arrivaltime){
            currtime = arrivaltime;
        }

        int waitingtime = currtime + preperationtime - arrivaltime;
        totalwaitingtime += waitingtime;
        currtime += preperationtime;
        }
        return static_cast<double> (totalwaitingtime) / customers.size();
    }
};
