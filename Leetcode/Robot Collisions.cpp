class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n  = positions.size();
        vector<int> indices(n) , result;
        stack<int> stack;

        for(int index=0 ; index<n ; ++index){
            indices[index] = index;
        }

        sort(indices.begin() , indices.end(), [&](int lhs, int rhs){return positions[lhs]
        < positions[rhs]; });

        for(int currentindex : indices){
            if(directions[currentindex] == 'R'){
                stack.push(currentindex);
            }
            else{
                while(!stack.empty() && healths[currentindex] > 0){
                    int topindex = stack.top();
                    stack.pop();

                    if(healths[topindex] > healths[currentindex]){
                        healths[topindex] -= 1;
                        healths[currentindex] = 0;
                        stack.push(topindex);
                    }
                    else if(healths[topindex] < healths[currentindex]){
                        healths[currentindex] -= 1;
                        healths[topindex]  = 0;
                    }
                    else{
                        healths[currentindex] = 0;
                        healths[topindex] = 0;
                    }
                }
            }
        }
        for(int index=0 ; index<n  ; ++index){
         if(healths[index] > 0){
            result.push_back(healths[index]);
        }
       }  
       return result;
    }
};
