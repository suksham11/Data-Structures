class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        int minchild1 = max(0 , n - 2*limit);
        int maxchild1 = min(n, limit);

        for(int i= minchild1; i<=maxchild1 ; i++){
            int N = n-i;
            int minchild2 = max(0 , N-limit);
            int maxchild2 = min(N, limit);
            
            ways += maxchild2 - minchild2 + 1;
        }
        return ways;
    }
};
