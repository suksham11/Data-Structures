class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
       int sum = 0;
       for(int i=0 ; i<rolls.size() ; i++){
        sum = sum + rolls[i];
       }
       int remainingsum = mean*(n+rolls.size()) - sum;
       if(remainingsum > 6*n || remainingsum < n){
        return {};
       }
       int distribution = remainingsum/n;
       int mod = remainingsum % n;
       vector<int> elements(n, distribution);
       for(int i=0 ; i<mod ; i++){
        elements[i]++;
       }
       return elements;
    }
};
