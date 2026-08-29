class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> a=nums;
        sort(nums.begin(),nums.end());
        vector<vector<int>> grps;
        unordered_map<int,int> tr;
        int id=-1;
        for(int i=0;i<nums.size();i++){
            if(i==0 || nums[i]-nums[i-1]>limit){
                grps.push_back({});
                id++;

            }
            grps[id].push_back(nums[i]);
            tr[nums[i]]=id;

        }
        vector<int> idx(grps.size(),0);
        for(int i=0;i<a.size();i++){
            a[i]=grps[tr[a[i]]][idx[tr[a[i]]]++];
            //idx++;
        }
        return a;
        
    }
};