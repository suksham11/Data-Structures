class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size();
        int x = 0;
        int y = 0;
        for(int i=0 ; i<n ; i++){
            int tempx = x;
            int tempy = y;
            for(int j=i ; j<n ; j++){
                char ch = path[j];
                if(ch == 'N'){
                    y++;
                }
                else if(ch == 'S'){
                    y--;
                }
                else if(ch == 'W'){
                    x--;
                }
                else{
                    x++;
                }
                if(x == tempx && y == tempy){
                    return true;
                }
            }
        }
        return false;
    }
};
