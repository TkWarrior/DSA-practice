class Solution {
public:
    int countSubstring(string s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        unordered_map<char, int> hashmap;
        int count = 0;
        while (r < n) {
            hashmap[s[r]]++;
            while (hashmap.size() > k) {
                hashmap[s[l]]--;
                if (hashmap[s[l]] == 0) {
                    hashmap.erase(s[l]);
                }
                l++;
            }
            count = count + (r - l + 1);
            r++;
        }

        return count;
    }

    int numberOfSubstrings(string s) {
        int k = 3;
        return countSubstring(s, k) - countSubstring(s, k - 1);
    }
};