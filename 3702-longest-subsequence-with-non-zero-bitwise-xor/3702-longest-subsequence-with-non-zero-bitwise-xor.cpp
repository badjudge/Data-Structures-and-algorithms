class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int nz=0;
        int tot=0;
        for(auto &i:nums){
            if(i>0 && !nz) nz++;
            tot^=i;
        }
        if(tot) return nums.size();
        if(nz) return nums.size()-1;
        return 0;
    }
};