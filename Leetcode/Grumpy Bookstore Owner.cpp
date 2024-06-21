class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int maxunsat = 0;
        int currentunsat = 0;
        for(int i=0 ; i<minutes ; i++){
            currentunsat += customers[i]  * grumpy[i];
        }

        maxunsat = currentunsat;
        int i=0 , j=minutes;
        while(j<n){
            currentunsat += customers[j] * grumpy[j];
            currentunsat -= customers[i] * grumpy[i];
            maxunsat = max(maxunsat, currentunsat);
            i++, j++;

        }
        int totalsat = maxunsat;
        for(int i=0 ; i<n ; i++){
            totalsat += customers[i] * (1-grumpy[i]);
        }
        return totalsat;
    }
};
