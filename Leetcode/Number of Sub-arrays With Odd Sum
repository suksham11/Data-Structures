class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int Mod = 1e9 + 7;
        int count = 0, prefixsum = 0;

        int oddcount = 0, evencount = 1;
        for(int num : arr){
            prefixsum += num;
            if(prefixsum % 2 == 0){
                count += oddcount;
                evencount++;
            }
            else{
                count += evencount;
                oddcount++;
            }
            count %= Mod;
        }
          return count;
        }
};
