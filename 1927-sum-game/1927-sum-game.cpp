class Solution {
public:
    bool sumGame(string num) {
        int ls=0;
        int rs=0;
        int lc=0;
        int rc=0;
        for(int i=0;i<num.size();i++){

            if(i<num.size()/2){
                 if(num[i]!='?') ls+=num[i]-'0';
                 else lc++;
            }
            else {
                if(num[i]=='?') rc++;
                else rs+=num[i]-'0';
            }
        }
        return (2*(ls-rs)!=9*(rc-lc));
    }
};