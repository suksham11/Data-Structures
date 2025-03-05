class Solution {
public:
    long long coloredCells(int n) {
       long long numbluecells = 1;
       int addend = 4; 
       while(--n){
        numbluecells += addend;
        addend += 4;

       }
       return numbluecells;
    }
};
