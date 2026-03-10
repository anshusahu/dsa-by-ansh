class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        map<int, int> freq;
        for(auto a: arr){
            freq[a]++;
        }
        vector<int> ans(n, -1);
        stack<pair<int,int>> s;
        for(int i=0; i<arr.size(); i++){
            while(!s.empty() && freq[arr[i]] > s.top().second){
                ans[s.top().first] = arr[i];
                s.pop();
            }
            s.push({i, freq[arr[i]]});
        }
        return ans;
    }
};
