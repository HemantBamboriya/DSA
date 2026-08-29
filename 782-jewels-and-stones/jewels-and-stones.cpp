class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool>vis(128,false);
        for(int i=0;i<jewels.size();i++){
            vis[jewels[i]]=true;
        }
        int count=0;
        for(int i=0;i<stones.size();i++){
            if(vis[stones[i]]==true){
                count++;
            }
        }
        return count;
    }
};