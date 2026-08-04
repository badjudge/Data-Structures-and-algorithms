class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]+1!=nums[i]){
                int d=nums[i]-nums[i-1]-1;
                while(d) ans.push_back(nums[i]-d--);
                 
            }
        }
        return ans;
    }
};