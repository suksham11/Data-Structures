class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
      colors.insert(colors.end(), colors.begin(), colors.begin() + (k-1));
      int count = 0;
      int left = 0;

      for(int r=0 ; r<colors.size(); ++r){
        if(r>0 && colors[r] == colors[r-1]){
            left = r;
        }
        if(r-left+1 >= k){
            count++;
        }
      }
      return count;
    }
};
