class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>circle;
        for(int i=1; i<=n ; ++i){
            circle.push_back(i);
        }
        int curr = 0;
        while(circle.size() > 1){
            int next = (curr +  k - 1) % circle.size();
            circle.erase(circle.begin() + next);
            curr = next;
        }
        return circle[0];
    }
};
