class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
       int n = code.size();
        vector<int> result(code.size(), 0);
    
        if(k==0) return result;
        int i=-1,  j=-1;
        if(k>0){
            i = 1;
            j = k;
        }
        else{
            i = n - abs(k);
            j = n - 1;
        }
         int winsum = 0;
         for(int p = i ; p<= j ; p++){
            winsum += code[p];
         }
         for(int k=0 ; k<n ; k++){
            result[k] = winsum;
            winsum -= code[i%n];
            i++;
            winsum += code[(j+1) %n ];
            j++;
         }
    return result;
    }
};
