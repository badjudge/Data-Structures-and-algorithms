class Solution {
    private:
    bool solve(vector<int> tr,string target,string &curr,int i,bool gr,string &res){
        if(i>=target.length()){
            if(gr){
               res=curr;
               return true;
            } return false;
        }
        for(char j='a';j<='z';j++){
            if(tr[j-'a']==0) continue;
            if(!gr && j<target[i]) continue;
            bool isg=gr || j>target[i];
            curr.push_back(j);
            tr[j-'a']--;
            if(solve(tr,target,curr,i+1,isg,res)) return true;;
            curr.pop_back();
            tr[j-'a']++;
        }
        return false;
    }
public:
    
    string lexGreaterPermutation(string s, string target) {
        vector<int> tr(26,0);
        for(auto &i:s){
            tr[i-'a']++;
        }
        string res="";
        string curr="";
        solve(tr,target,curr,0,false,res);
        return res;
    }
};