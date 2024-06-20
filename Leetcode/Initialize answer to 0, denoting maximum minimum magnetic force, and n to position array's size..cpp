class Solution {
public:
    
    
    bool canplace(int x, vector<int> &position , int m){
        int prevball = position[0];
        int ballsplaced = 1;


        for(int i=1 ; i<position.size() && ballsplaced < m ; ++i){
            int currpos = position[i];
            if(currpos - prevball >= x){
              ballsplaced+=1;
              prevball = currpos;

            }
        }
        return ballsplaced == m;
    }
    
    
    
    
    
    int maxDistance(vector<int>& position, int m) {
        int ans=0;
        int n = position.size();
        sort(position.begin() , position.end());
        int low = 1;
        int high = ceil(position[n-1]/(m-1.0));
            while(low<=high){
                int mid = low+(high - low)/2;
                if(canplace(mid,position , m)){
                    ans = mid;
                    
                    low  = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            return ans;        
    }
};
