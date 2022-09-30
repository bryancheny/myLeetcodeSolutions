class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int,int> hash;
        for (int i = 0; i < indices.size(); i++) {
            hash[indices[i]] = i;
        }
        sort(indices.begin(),indices.end());
        string res; 
        int curr = 0;
        for (int i = 0; i < indices.size(); i++) {
            res.insert(res.end(),s.begin() + curr, s.begin() + indices[i]);
            for (int j = 0; j < sources[hash[indices[i]]].length(); j++) {
                if (indices[i] + j >= s.length() || sources[hash[indices[i]]][j] != s[indices[i]+j]) {
                    curr = indices[i];
                    break;
                }
                if (j == sources[hash[indices[i]]].length() - 1) { // found string 
                    curr = indices[i] + j + 1;
                    res.insert(res.end(),targets[hash[indices[i]]].begin(),targets[hash[indices[i]]].end());
                }
            }
        }
        res.insert(res.end(),s.begin() + curr, s.end());
        return res;
    }
};
