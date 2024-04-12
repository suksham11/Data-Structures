class Solution {
public:
    int trap(vector<int>& h) {
     int  n = h.size();
     int leftmax = 0 , rightmax = 0 , left = 0 , right = n-1;
     int result = 0;
     while(left <= right){
     if(h[left] <= h[right]){
        if(h[left]>=leftmax) leftmax = h[left];
        else result+= leftmax-h[left];
        left++;
     } 
     else{
        if(h[right] >= rightmax) rightmax = h[right];
        else result += rightmax - h[right];
        right--;
     }
    }
    return result;
    }
};
