class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";

        string ans;
        ans = (numerator > 0)^(denominator > 0) ? "-":"";
        long n = abs(numerator);
        long d = abs(denominator);
        ans+=to_string(n/d);
        n=n%d;
        if(!n) return ans;
        ans += ".";
        unordered_map<long, int>mp;
        while(n){
            if(mp[n]){
                ans.insert(mp[n], "(");
                ans+= ")";
                break;
            }
            else{
                mp[n] = ans.size();
                n*=10;
                ans += to_string(n/d);
                n = n%d;
            }
        }
        return ans;
    }
};
