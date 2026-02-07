class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto& str : strs) {
            string temp = str;
            sort(str.begin(), str.end());
            m[str].push_back(temp);
        }

        vector<vector<string>> ans;
        for (auto [k, v] : m) {
            ans.push_back(v);
        }

        return ans;
    }


};
