#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    TrieNode* fail;
    vector<int> output; // Stores matched pattern indices
};

class AhoCorasick {
private:
    TrieNode* root;

public:
    AhoCorasick() {
        root = new TrieNode();
        root->fail = nullptr;
    }

    // Insert pattern into Trie
    void insertPattern(string pattern, int index) {
        TrieNode* node = root;
        for (char c : pattern) {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->output.push_back(index); // Store pattern index at leaf node
    }

    // Build Failure Links (BFS)
    void buildFailureLinks() {
        queue<TrieNode*> q;
        root->fail = root;
        
        for (auto& [c, child] : root->children) {
            child->fail = root;
            q.push(child);
        }

        while (!q.empty()) {
            TrieNode* node = q.front(); q.pop();
            for (auto& [c, child] : node->children) {
                TrieNode* failNode = node->fail;
                while (failNode != root && !failNode->children.count(c))
                    failNode = failNode->fail;

                if (failNode->children.count(c) && failNode->children[c] != child)
                    child->fail = failNode->children[c];
                else
                    child->fail = root;

                child->output.insert(child->output.end(),
                                     child->fail->output.begin(),
                                     child->fail->output.end());
                q.push(child);
            }
        }
    }

    // Search text for patterns
    vector<pair<int, int>> search(string text, vector<string>& patterns) {
        vector<pair<int, int>> result; // Stores (position, pattern index)
        TrieNode* node = root;

        for (int i = 0; i < text.size(); i++) {
            while (node != root && !node->children.count(text[i]))
                node = node->fail;

            if (node->children.count(text[i]))
                node = node->children[text[i]];

            for (int patternIndex : node->output)
                result.push_back({i, patternIndex});
        }
        return result;
    }
};

// Driver Code
int main() {
    vector<string> patterns = {"he", "she", "his", "hers"};
    string text = "ahishers";

    AhoCorasick ac;
    for (int i = 0; i < patterns.size(); i++)
        ac.insertPattern(patterns[i], i);

    ac.buildFailureLinks();
    vector<pair<int, int>> matches = ac.search(text, patterns);

    cout << "Pattern Matches:\n";
    for (auto& [pos, index] : matches)
        cout << "Pattern \"" << patterns[index] << "\" found at index " << pos - patterns[index].size() + 1 << endl;

    return 0;
}
