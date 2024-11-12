class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());

        int m = queries.size();
        vector<pair<int, int>> querieswithindex;
        for(int i=0 ; i<m ; ++i){
            querieswithindex.push_back({queries[i],
            i});
        
        }
        sort(querieswithindex.begin() , querieswithindex.end());
        vector<int> result(m);
        int maxb = 0;
        int indexitem = 0;
        for(auto&[query, qindex] : querieswithindex){
            while(indexitem < items.size() && items[indexitem][0] <= query){
                maxb = max(maxb , items[indexitem][1]);
                ++indexitem;
            }
            result[qindex] = maxb;
        }
        return result;
    }
};
