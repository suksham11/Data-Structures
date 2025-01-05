class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffarray(n, 0);
        for(auto shift : shifts){
            if(shift[2] == 1){
                diffarray[shift[0]]++;

                if(shift[1] + 1 < n){
                    diffarray[shift[1] + 1]--;
                }
            }
    
        else{
            diffarray[shift[0]]--;

            if(shift[1] + 1 < n){
                diffarray[shift[1] + 1]++;
            }
        }
    }
    string result(n, ' ');
    int numberofshifts = 0;
    for(int i=0 ; i<s.size() ; i++){
        numberofshifts = (numberofshifts + diffarray[i]) % 26;
        
        if(numberofshifts < 0)
           numberofshifts += 26;
        
        result[i] = 'a' + (s[i] - 'a' + numberofshifts) % 26;
    } 
    return result;      
    }
};
