class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        //vector<vector<int>> tr(n,vector<int>(10,0));
        unordered_map<int,int> rr;
        for(auto &i:reservedSeats){
            rr[i[0]]|=(1<<i[1]);
        }
        int c=2*n;
        for(auto &[a,i]:rr){
            bool lb=i&((1<<2)|(1<<3)|(1<<4)|(1<<5));
            bool mb=i&((1<<4)|(1<<5)|(1<<6)|(1<<7));
            bool rb=i&((1<<6)|(1<<7)|(1<<8)|(1<<9));
            if(!lb&&!rb&&!mb) continue;
            else if(!lb||!mb||!rb) c--;
            else c-=2;
        }
        return c;

    }
};