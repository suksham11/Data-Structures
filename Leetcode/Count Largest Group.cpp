class Solution {
public:
    int findDigitSum(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxsize = 0;
        int count = 0;
        for(int num = 1 ; num <= n; num++){
            int digitsum = findDigitSum(num);
            mp[digitsum]++;
            if(mp[digitsum] == maxsize){
                count++;
            }
            else if(mp[digitsum] > maxsize){
                maxsize = mp[digitsum];
                count = 1;
            }
        }
        return count;
    }
};
