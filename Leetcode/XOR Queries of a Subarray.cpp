class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> cumxor(n,0);
        cumxor[0] = arr[0];
        for(int i=1 ; i<n ; i++){
            cumxor[i] = cumxor[i-1] ^ arr[i];
        }
        vector<int> result;
        for(vector<int>&query : queries){
            int L = query[0];
            int R = query[1];

            int xor_val = cumxor[R] ^ (L==0 ? 0 : cumxor[L-1]);
            result.push_back(xor_val);
        }
        return result;
    }
};
