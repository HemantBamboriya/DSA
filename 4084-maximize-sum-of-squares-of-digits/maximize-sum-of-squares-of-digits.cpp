class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if(sum> num*9){
            return "";
        }

        int nine= sum/9;
        int remaining= sum % 9;
        string result(nine,'9');
        if(remaining>0){
           result += (remaining+'0');
        }
        result.append(num-result.length(),'0');

        return result;;
    }
};