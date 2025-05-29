#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class RadixTreeNode {
public:
    unordered_map<string, RadixTreeNode*> children;
    bool isEnd;

    RadixTreeNode() {
        isEnd = false;
    }
};

class RadixTree {
public:
    RadixTreeNode* root;

    RadixTree() {
        root = new RadixTreeNode();
    }

    void insert(string word) {
        RadixTreeNode* node = root;
        while (true) {
            bool found = false;
            for (auto it = node->children.begin(); it != node->children.end(); ++it) {
                string key = it->first;
                int len = commonPrefixLength(key, word);
                if (len == 0) continue;

                if (len < (int)key.length()) {
                    RadixTreeNode* child = it->second;
                    string remainingKey = key.substr(len);

                    RadixTreeNode* newChild = new RadixTreeNode();
                    newChild->children[remainingKey] = child;
                    newChild->isEnd = child->isEnd;

                    node->children.erase(it);
                    node->children[key.substr(0, len)] = newChild;

                    child->isEnd = false;
                    node = newChild;
                } else {
                    node = it->second;
                }

                word = word.substr(len);
                found = true;
                break;
            }

            if (!found) break;

            if (word.empty()) {
                node->isEnd = true;
                return;
            }
        }

        node->children[word] = new RadixTreeNode();
        node->children[word]->isEnd = true;
    }

    bool search(string word) {
        RadixTreeNode* node = root;
        while (true) {
            bool found = false;
            for (auto& pair : node->children) {
                const string& key = pair.first;
                RadixTreeNode* child = pair.second;

                int len = commonPrefixLength(key, word);
                if (len == (int)key.length()) {
                    word = word.substr(len);
                    node = child;
                    found = true;
                    break;
                }
            }

            if (!found) return false;
            if (word.empty()) return node->isEnd;
        }
    }

private:
    int commonPrefixLength(const string& a, const string& b) {
        int len = min(a.length(), b.length());
        int i = 0;
        while (i < len && a[i] == b[i]) i++;
        return i;
    }
};

int main() {
    RadixTree tree;
    tree.insert("apple");
    tree.insert("app");
    tree.insert("bat");
    tree.insert("ball");

    cout << (tree.search("apple") ? "true" : "false") << endl;
    cout << (tree.search("app") ? "true" : "false") << endl;
    cout << (tree.search("appl") ? "true" : "false") << endl;
    cout << (tree.search("ball") ? "true" : "false") << endl;
    cout << (tree.search("batman") ? "true" : "false") << endl;

    return 0;
}
