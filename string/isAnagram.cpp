// is Anagram

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> charCountMap;
        for(int i = 0; i < s.size(); i++) {
            charCountMap[s[i]]++;
        }

        for(int i = 0; i < t.size(); i++) {
            if(charCountMap.find(t[i]) == charCountMap.end())
                return false;
            charCountMap[t[i]]--;
        }

        for(auto x : charCountMap) {
            if(x.second != 0) return false;
        }

        return true;
    }
};

int main() {
	string s = "listen", t = "silent";
	Solution sol = Solution();
	if(sol.isAnagram(s,t)) {
		cout << s << " and " << t << " are anagrams";
	} else {
		cout << s << " and " << t << " not are anagrams";
	}
}