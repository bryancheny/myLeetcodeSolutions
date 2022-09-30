class Solution {
public:
    string minWindow(string &s, string &t) {
        // unordered_map<char,unordered_set<list<int>::iterator>> hash;
        unordered_map<char,int> count;
        int minidx = 0, minlen = INT_MAX;
        for (auto c:t) {
            count[c]++;
        }
        unordered_map<char,queue<list<int>::iterator>> hash;
        int seen = 0;
        list<int> mylist;
        for (int i = 0; i < s.length(); i++) {
            if (count.find(s[i]) != count.end()) {
                if (seen < t.length()) {
                    if (hash[s[i]].size() < count[s[i]]) {
                        seen++;
                        mylist.push_back(i);
                        hash[s[i]].push(--mylist.end());
                        if (seen == t.length()) {
                            minidx = mylist.front();
                            minlen = i - mylist.front() + 1;
                        }
                    }
                    else {
                        auto old = hash[s[i]].front();
                        mylist.splice(mylist.end(),mylist,old);
                        *old = i;
                        hash[s[i]].pop();
                        hash[s[i]].push(old);
                    }
                }
                
                else {
                    auto old = hash[s[i]].front();
                    if (old == mylist.begin()) {
                        mylist.splice(mylist.end(),mylist,old);
                        if(i - mylist.front() + 1 < minlen) {
                            minlen = i - mylist.front() + 1;
                            minidx = mylist.front();
                        }
                    }
                    else mylist.splice(mylist.end(),mylist,old);
                    *old = i;
                    hash[s[i]].pop();
                    hash[s[i]].push(old);
                }
            }
        }
        if (seen < t.length()) return "";
        return s.substr(minidx,minlen);
    }
};
