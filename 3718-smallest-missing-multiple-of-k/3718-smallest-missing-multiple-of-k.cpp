class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> tr;
        for(auto &i:nums){
            if(i%k==0)tr.insert(i);
        }
        for(int i=k;i<=100+k;i+=k){
            if(tr.find(i)==tr.end()) return i;
        }
        return 0;
    }
};