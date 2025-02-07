class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> product;
        int totaltuples = 0;    // counting tuples count
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                int prod = nums[i] * nums[j];    
                // If the product exists in the map, add 8 times its frequency
                if(product.find(prod) != product.end()){
                    totaltuples += 8 * product[prod];
                   
                }
                product[prod]++;// Increment the frequency of the product
            }
        }
        return totaltuples;
    }
};
