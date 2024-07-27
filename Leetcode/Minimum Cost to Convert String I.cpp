class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long totalcost = 0;
        vector<vector<long long>> mincost(26, vector<long long> (26,INT_MAX));

        for(int i=0 ; i<original.size() ; ++i){
            int startchar = original[i] - 'a';
            int endchar = changed[i] - 'a';
            mincost[startchar][endchar] = min(mincost[startchar][endchar], (long long)cost[i]);
        }

        for(int k=0 ; k<26 ; ++k){
            for(int i=0 ; i<26 ; ++i){
                for(int j=0 ; j<26 ; ++j){
                    mincost[i][j] = min(mincost[i][j] , mincost[i][k] + mincost[k][j]);
                }
            }
        }

        for(int i=0 ; i<source.size() ; ++i){
            if(source[i] == target[i]){
               continue;
            }
            int sourcechar = source[i] - 'a';
            int targetchar = target[i] - 'a';

            if(mincost[sourcechar][targetchar] >= INT_MAX){
                return -1;
            }
            totalcost += mincost[sourcechar][targetchar];
        }
        return totalcost;
    }
};
