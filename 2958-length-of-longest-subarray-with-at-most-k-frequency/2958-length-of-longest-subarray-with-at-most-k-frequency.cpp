class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> tr;
        int j=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(++tr[nums[i]]<=k) l=max(l,i-j+1);
            else{
                while(j<=i && tr[nums[i]]>k){
                    tr[nums[j]]--;
                    j++;
                    l=max(l,i-j+1);
                }
            }
        }
        return l;
    }
};