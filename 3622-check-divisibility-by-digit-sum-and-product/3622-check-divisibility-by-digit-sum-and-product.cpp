class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int tn=n;
        while(n){
            int i=n%10;
            n/=10;
            sum+=i;
            product*=i;
        }
        return (tn%(sum+product)==0);
    }
};