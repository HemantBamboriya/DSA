class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans;
        int count=0;
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                count++;
                 ans.push_back(count%2);
                
            }else{
                ans.push_back(count%2);
                count--;
            }
        }
        return ans;
    }
};