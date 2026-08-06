class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<n+15;i++){
            int r=1;
            int tp=i;
            while(tp){
                r=r*(tp%10);
                tp/=10;
            }
            if(r%t==0) return i;
        }
        return 0;
    }
};