class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> tr;
        unordered_map<int,int> in,out;
        //vector<int> out;
        for(auto &i:pairs){
            tr[i[0]].push_back(i[1]);
            in[i[1]]++;
            out[i[0]]++;
        }
        int start=pairs[0][0];
        for(auto &it:tr){
            if(out[it.first]-in[it.first]==1){
start=it.first;
break;
            } 
        }
        vector<int> ep;//euler path
        stack<int> st;
        st.push(start);
        while(!st.empty()){
            int n=st.top();
            if(!tr[n].empty()){
                st.push(tr[n].back());
                tr[n].pop_back();
            }else{
                ep.push_back(st.top());
                st.pop();
            }
        }reverse(ep.begin(),ep.end());
        vector<vector<int>> res;
        for(int i=0;i<ep.size()-1;i++){
            res.push_back({ep[i],ep[i+1]});
        }
        return res;
    }
};