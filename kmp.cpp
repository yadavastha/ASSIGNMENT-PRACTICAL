#include <iostream>
#include<vector>
using namespace std;

int kmp(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    vector<int> lps(m, 0);  

    int len = 0;
    for (int i = 1; i < m;) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }


    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++; j++;
        }
        if (j == m) {
            return i - j; 
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return -1;  
}

int main() {
    string pattern = "aaaaaab", text = "aaaaaaaamaaaaaab";
    int index = kmp(text, pattern);
    if (index == -1)
        cout << "The pattern is not found";
    else
        cout << "The pattern is found in the given string at index " << index;
    return 0;
}
