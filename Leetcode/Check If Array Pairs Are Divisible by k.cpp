class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remaindercount;
        for(auto i : arr) remaindercount[(i % k + k) % k]++;

        for(auto i : arr){
            int rem = (i%k+k) % k;
            if(rem == 0){
                if(remaindercount[rem] % 2 == 1)  return false;
            }
            else if(remaindercount[rem] != remaindercount[k-rem])
            return false;

        }
        return true;
    }
};
