class Solution {
public:
    int countTriplets(vector<int>& arr) {
       vector<int> prefixXOR(arr.begin(), arr.end());
       prefixXOR.insert(prefixXOR.begin(),0);
       int size = prefixXOR.size();

       for(int i=1; i<size ; ++i) prefixXOR[i] ^= prefixXOR[i-1];

       int cnt = 0;

       for(int s = 0 ; s<size ; ++s){
        for(int e = s+1 ; e<size ; ++e){
            if(prefixXOR[s] == prefixXOR[e]){
                cnt += e-s-1;
            }
        }
       }
       return cnt;
    }
};
