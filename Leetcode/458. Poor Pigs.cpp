#pragma GCC optimize("03")
class Solution {
public:
    int poorPigs(int buckets, int timedetect, int timetest) {
        signed i=0 ,  b = timetest/timedetect + 1 , p = 1;
        #pragma unroll
        for(; p<buckets ; i++)
             p*=b;
        return i;
        
    }

};
