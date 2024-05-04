class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> count(limit + 1, 0);
        for(int p: people) count[p]++;
        int ind = 0;
        for(int val = 1; val <= limit ; val++){
            while(count[val]-- > 0) 
              people[ind++]  = val;
        }
        int boats = 0;
        int start = 0;
        int end = people.size() - 1;
        while(start <= end){
            if(people[start] + people[end] <= limit){
                start++;
                end--;
            }
            else{
                end--;
            }
            boats++;
        }
       return boats; 
    }
};
