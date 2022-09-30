class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int size = 1 + haystack.length() - needle.length();
        for (int i = 0; i < size; i++) {
            for (int j = i; j < i + needle.size(); j++) {
                if (haystack[j] != needle[j-i]) {
                    break;
                }
                else if (j == i + needle.size() - 1) return i;
            }
        }
        return -1;
    }
};
