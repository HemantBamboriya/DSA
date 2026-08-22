class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long pro=1;
        int original=n;
        while(n>0){
            int lastdig=n%10;
            sum += lastdig;
            pro *= lastdig;
            n= n/10;
        }
        int ans=sum +pro;
        if(original%ans==0){
            return true;
        }
        return false;
        
    }
};