class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n) return *max_element(nums.begin(),nums.end());
        
        unordered_map<int,int> tr;
        for(int i=0;i<=n-k;i++){
            for(int j=i;j<i+k;j++){
                tr[nums[j]]++;
            }
        }
        int m=-1;
        for(auto &it:tr){
            if(it.second==1) m=max(it.first,m);
        }
        
        return m;
    }
};