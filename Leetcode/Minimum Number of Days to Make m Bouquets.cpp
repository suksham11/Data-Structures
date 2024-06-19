class Solution {
public:
    int canmake(vector<int>& bloomday, int m , int k){ 
        int bouqcount = 0;
        int consecutivecount = 0;

        for(int i=0; i<bloomday.size() ; i++){
            if(bloomday[i] <= m){
                consecutivecount++;
            }else{
                consecutivecount = 0;
            }
            if(consecutivecount == k){
                bouqcount++;
                consecutivecount = 0;
            }
        }
        return bouqcount;
    }
    
    int minDays(vector<int>& bloomday, int m, int k) {
        int n = bloomday.size();
  
        int s = 0;
        int e = *max_element(begin(bloomday), end(bloomday));

        int minDays = -1;

        while(s <= e){
            int mid = s+(e-s)/2;
            
            if(canmake(bloomday, mid, k) >= m){
                minDays = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return minDays;
    }
};

