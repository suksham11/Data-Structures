class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1 , right = *max_element(quantities.begin() , quantities.end());
        auto candistribute = [&](int maxload){
            int storesneeded = 0;
            for(int quantity : quantities){
                storesneeded += (quantity + maxload - 1)/maxload;
            }
            return storesneeded <= n;
        };
        while(left < right){
        int mid = left + (right - left) / 2;   
        if(candistribute(mid)){
          right = mid;
        }
        else{
            left = mid + 1;
        }
        }
        return left; 
    }
};
