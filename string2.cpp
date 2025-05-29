#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> chars;
    int left = 0, right = 0, maxLen = 0;
    while (right < s.size()) {
        if (chars.find(s[right]) == chars.end()) {
            chars.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        } else {
            chars.erase(s[left]);
            left++;
        }
    }
    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
