class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>freq;
        while(true){
            int sum =0;
            while(n!=0){
                sum += pow(n%10,2.0);
                n=n/10;
            }
            if(sum ==1) return true;
            n=sum;
            if(freq.find(n)!=freq.end()){
                return false;
            }
            freq[n]++;
            
        }
        
    }
};