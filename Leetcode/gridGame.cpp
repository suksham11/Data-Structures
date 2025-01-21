class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemainSum  = accumulate(begin(grid[0]), end(grid[0]),0LL);
        long long secondRowRemainSum = 0;
        long long minimizedRobot2sum = LONG_LONG_MAX;
        for(int robot1col = 0 ; robot1col < grid[0].size() ; robot1col++){
            firstRowRemainSum -= grid[0][robot1col];
            long long bestofRobot2 = max(firstRowRemainSum , secondRowRemainSum);
            minimizedRobot2sum = min(minimizedRobot2sum , bestofRobot2);
            secondRowRemainSum += grid[1][robot1col];
        }
        return minimizedRobot2sum;
    }
};
