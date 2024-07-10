class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> paths;

        for(const string&log : logs){
            if(log == "../"){
                if(!paths.empty()){
                    paths.pop_back();
                }
            }
                else if(log != "./"){
                    paths.push_back(log);
                }
            }
        return paths.size();
    }
};
