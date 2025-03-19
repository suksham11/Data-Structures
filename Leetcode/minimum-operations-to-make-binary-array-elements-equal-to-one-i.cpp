class Solution {
public:
    int minOperations(vector<int>& nums) {
        deque<int> flipqueue;
        int count = 0;

        for(int i=0 ; i<nums.size() ; i++){
            while(!flipqueue.empty() && i>flipqueue.front() + 2){
                flipqueue.pop_front();
            }
            if((nums[i] + flipqueue.size()) % 2 == 0){
                if(i+2 >= nums.size()){
                    return -1;
                }
                count++;
                flipqueue.push_back(i);
            }
        }
        return count;
    }
};
