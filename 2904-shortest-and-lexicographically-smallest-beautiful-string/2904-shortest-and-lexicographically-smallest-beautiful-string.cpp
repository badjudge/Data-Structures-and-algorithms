class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int z=0;
        int o=0;
        int i=0;
        string ss="";
        for(int j=0;j<s.size();j++){
            if(s[j]=='0') z++;
            else o++;
            while(o>k){
                if(s[i]=='1') o--;
                i++;
            }
            while(s[i]=='0'&& i<j) i++;
            if(o==k){
                string cur=s.substr(i,j-i+1);
                if(ss=="" || ss.size()>cur.size() || (ss.size()==cur.size() && ss>cur)) ss=cur;
                //else ss=min(ss,s.substr(i,j-i+1));
            } 
        }
        return ss;
    }
};