class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        for(int x:asteroids){
            bool destroy=false;
            while(!st.empty() && x<0 && st.top()>0){
                if(st.top()<abs(x)){
                    st.pop();
                    continue;
                }else if(st.top()==abs(x)){
                    st.pop();
                }
                destroy=true;
                break;
            }
            if(!destroy){
                st.push(x);       
           }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};