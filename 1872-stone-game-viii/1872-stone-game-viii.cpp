class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> ps(n,0);
        ps[0]=stones[0];
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+stones[i];
        }
        vector<int> bu(n,0);
        bu[n-1]=ps[n-1];
        for(int i=n-2;i>=1;i--){
            int t=ps[i]-bu[i+1];
            int nt=bu[i+1];
            bu[i]=max(t,nt);
        }
        return bu[1];
    }
};