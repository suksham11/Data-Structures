class Solution {
public:
    int passThePillow(int n, int time) {
        int idx = 1;
        int dir = 1; // l to r

        while(time > 0){
            if(idx + dir >= 1 && idx + dir <= n){
                idx += dir;
                time--;
            }
            else{
                dir *= -1;
            }
        }
        return idx;
    }
};
