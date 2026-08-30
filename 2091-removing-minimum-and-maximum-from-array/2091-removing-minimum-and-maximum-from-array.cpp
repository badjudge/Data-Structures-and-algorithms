class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<nums[mini]) mini=i;
            if(nums[i]>nums[maxi])maxi=i;
        }
        int fc=max(mini,maxi)+1;
        int bc=nums.size()-min(mini,maxi);
        int dc=min(maxi,mini)+nums.size()-max(mini,maxi)+1;
        return min(fc,min(dc,bc));
    }
};