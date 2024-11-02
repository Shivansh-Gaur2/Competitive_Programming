#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define M 3
#define N 4

class Node{
    public : 
    char s;
    unordered_map<char, Node*> children;
    string word;
    bool isTerminal;

    Node(char s){
        this->s = s;
        isTerminal = false;
        word = "";
    }
};

class Trie{
    public : 
    Node* root;
    Trie(){
        root = new Node('\0');
    }

    void addWord(string word){
        Node * temp = root;
        for(auto ch : word){
            if(temp->children.count(ch) == 0){
                temp ->children[ch] = new Node(ch);
            }
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
        temp->word = word;
    }
};

void dfs(char board[M][N], Node* node, int i, int j, bool visited[][N], unordered_set<string>&output){
     char ch = board[i][j];
     if(node->children.count(ch) == 0){
        return;
     }

    node = node->children[ch];
    visited[i][j] = true;

    if(node->isTerminal){
        output.insert(node->word);
    }

    int dx[] = {0, 1, 1 ,1, 0, -1, -1, -1};
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

for(int k = 0; k < 8; k++){
    int ni = i + dx[k];
    int nj = j + dy[k];

    if(ni >= 0 && nj >= 0 && ni < M && nj < N && !visited[ni][nj]){
        dfs(board, node, ni, nj, visited, output);
    }
}
visited[i][j] = false;
return;
}

int main(){
    string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO", "TUNES", "CAT"};
    char board[M][N] = {
        {'S', 'E', 'R', 'T'},
        {'U', 'N', 'K', 'S'},
        {'T', 'C', 'A', 'T'}
    };

    Trie t;
    for(auto w : words){
        t.addWord(w);
    }

    unordered_set<string> output;
    bool visited[M][N] = {0};

    for(int i = 0 ; i < M; i++){
        for(int j = 0; j < N; j++){
            dfs(board, t.root, i, j, visited, output);
        }
    }

    for(auto str : output){
        cout << str << endl;
    }
    
    return 0;
}