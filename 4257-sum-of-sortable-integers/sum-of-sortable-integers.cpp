class Solution {
public:
bool KMPSearch(vector<int>&vec1,vector<int>&text){
    int m=vec1.size();
    int n=text.size();
    vector<int>LPS(m,0);
    int length=0;
    int i=1;
    while(i<m){
        if(vec1[i]==vec1[length]){
            length++;
            LPS[i]=length;
            i++;
        }else{
            if(length!=0){
                length= LPS[length-1];
            }else{
                i++;
            }
        }
    }

     i=0;
    int j=0;

    while(i<n){
        if(vec1[j]==text[i]){
            i++;
            j++;

            if(j==m){
                return true;
            }
        }else{
            if(j!=0){
                j= LPS[j-1];
            }else{
                i++;
            }
        }
    }
return false;
}



bool  rotationPossible(vector<int>&vec1,vector<int>&vec2){
    vector<int>text=vec2;
    text.insert(end(text),begin(vec2),end(vec2));

    return KMPSearch(vec1,text);

}


    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());

        int result=0;
        for(int k=1;k<=n;k++){
            if(n%k!=0){
                continue;
            }

            bool valid=true;

            for(int start=0;start<n;start+=k){
                vector<int>vec1(nums.begin()+start,nums.begin()+start+k);
                vector<int>vec2(sorted.begin()+start,sorted.begin()+start+k);

                if(!rotationPossible(vec1,vec2)){
                valid=false;
                break;
                }
            }

            if(valid){
                result += k;
            }
        }
       return result; 
    }
};