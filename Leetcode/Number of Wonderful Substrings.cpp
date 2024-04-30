class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> count(1024 , 0);
        long long res = 0;
        int prefixor = 0;
        count[prefixor] = 1;

        for(char ch: word){
            int charindex = ch-'a';
            prefixor ^= 1 << charindex;
            res += count[prefixor];
            for(int i=0 ; i<10 ; i++){
                res += count[prefixor ^ (1<<i)];
            }
            count[prefixor]++;
        }
        return res;
    }
};
