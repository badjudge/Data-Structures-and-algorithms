class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.size());
        lps[0]=0;
        int l=0;int i=1;
        //int ml=0;
        while(i<s.size()){
            if(s[i]==s[l]) {
                l++;
                lps[i]=l;
                i++;
                //ml=max(ml,l);
            }else{
                if(l>0) l=lps[l-1];
                else {
                    lps[i]=0;
                    l=0;
                    i++;
                }
            }
        }
        return s.substr(0,l);
    }
};