class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       
        stack<int> s;
        int n = arr.size();

        vector<int> l,r;
        int mod = pow(10,9) + 7;

        for(int i=0 ; i<arr.size() ; i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                l.push_back(-1);
            }
            else{
                l.push_back(s.top());
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1 ; i>=0 ; i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.empty()){
                r.push_back(arr.size());
            }
            else{
                r.push_back(s.top());
            }
            s.push(i);
        }
        reverse(r.begin() , r.end());

        long long ans = 0;

        for(int i=0 ; i<arr.size() ; i++){
            long long int k = i-(l[i]+1)+r[i]-1-i+1;
            long long  int p = (long long)(i-(l[i]+1)) * (long long)(r[i]-1-i);
            k+=p;
            ans+=(arr[i]*k)%mod;
            ans=ans%mod;
        }
        return ans;
    }
};
