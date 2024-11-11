class Solution {
public:
    bool checkprime(int x){
        for(int i=2 ; i<=sqrt(x) ; i++){
            if(x%i == 0) return 0;
        }
        return 1;
    }
    bool primeSubOperation(vector<int>& nums) {
        int maxelement = *max_element(nums.begin() , nums.end());

         vector<int> previousprime(maxelement+1 , 0);
         for(int i=2 ; i<=maxelement ; i++){
            if(checkprime(i)){
                previousprime[i] = i;
            }
            else{
                previousprime[i] = previousprime[i-1];
            }
         }
         for(int i=0 ; i<nums.size(); i++){
            int bound;
            if(i==0){
                bound = nums[0];
            }
            else{
                bound = nums[i] - nums[i-1];
            }
        if(bound <= 0){
            return 0;
        }
        int largestprime = previousprime[bound - 1];
        nums[i] = nums[i] - largestprime;
         }
         return 1;
    }
};
