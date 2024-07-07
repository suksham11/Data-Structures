class Solution {
    public int numWaterBottles(int numbottles, int numexchange) {
        int ans = numbottles;
        while(numbottles >= numexchange){
            int newbottles = numbottles / numexchange;
            int rembottles = numbottles % numexchange;
            ans = ans + newbottles;
            numbottles = newbottles + rembottles;
        }
        return ans;
    }
}
