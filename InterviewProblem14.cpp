#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// class Trie
// {
//   public:
//     struct TrieNode
//     {
//         vector<TrieNode *> children;
//         TrieNode()
//         {
//             children = vector<TrieNode *>(26, NULL);
//         }
//         ~TrieNode()
//         {
//             for (int i = 0; i < 26; i++)
//             {
//                 if (children[i] != NULL)
//                 {
//                     delete children[i];
//                 }
//             }
//         }
//     };
//     TrieNode *root;
//     Trie()
//     {
//         root = new TrieNode();
//     }
//     ~Trie()
//     {
//         delete root;
//     }

//     bool find(string word, TrieNode *&newRoot)
//     {
//         for (int i = 0; i < word.size(); i++)
//         {
//             if (newRoot->children[word[i] - 'a'] == NULL)
//             {
//                 return false;
//             }
//             newRoot = newRoot->children[word[i] - 'a'];
//         }
//         return true;
//     }

//     void insert(string word)
//     {
//         TrieNode *newRoot = root;
//         for (int i = 0; i < word.size(); i++)
//         {
//             if (newRoot->children[word[i] - 'a'] == NULL)
//             {
//                 newRoot->children[word[i] - 'a'] = new TrieNode();
//             }
//             newRoot = newRoot->children[word[i] - 'a'];
//         }
//     }

//     bool startsWith(string prefix)
//     {
//         TrieNode *newRoot = root;
//         return find(prefix, newRoot);
//     }
// };

// class Solution
// {
//     Trie* t;
//     int dx[4] = {1, -1, 0, 0};
//     int dy[4] = {0, 0, 1, -1};
//     int borderRow;
//     int borderCol;
//     vector<string> ans;
//   public:
//     vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
//     {
//         t = new Trie();
//         borderRow = board.size();
//         if(borderRow == 0 || words.size() == 0)
//         {
//             return ans;
//         }
//         borderCol = board[0].size();
//         vector<vector<bool>> visit(borderRow, vector<bool>(borderCol, false));
//         map<string, bool> check;
//         string str = "";
//         for (int i = 0; i < words.size(); i++)
//         {
//             for (int r = 0; r < borderRow; r++)
//             {
//                 for (int c = 0; c < borderCol; c++)
//                 {
//                     if(board[r][c] == words[i][0])
//                     {
//                         if(check[words[i]] == true)
//                             continue;
//                         if (t->startsWith(words[i]))
//                         {
//                             //cout << r << c << "  1" << words[i] << endl;
//                             check[words[i]] = true;
//                             ans.push_back(words[i]);
//                         }
//                         else
//                         {
//                             visit[r][c] = true;
//                             if (DFS(board, visit, r, c,  str + board[r][c], words[i]))
//                             {
//                                 //cout << r << c <<"  2" << words[i] << endl;
//                                 check[words[i]] = true;
//                                 ans.push_back(words[i]);
//                             }
//                             visit[r][c] = false;
//                         }
                        
//                     }
//                 }
//             }
            
//         }
//         return ans;
//     }

//     bool DFS(vector<vector<char>> &board, vector<vector<bool>> &visit, int row, int col, string str, string word)
//     {
//         if(str.size() >= word.size())
//         {
//             //cout << str << endl;
//             t->insert(str);
//             if(str == word)
//                 return true;
//             return false;
//         }
//         for (int i = 0; i < 4; i++)
//         {
//             int newRow = row + dx[i];
//             int newCol = col + dy[i];
//             if(newRow < 0 || newRow >= borderRow || newCol < 0 || newCol >= borderCol)
//                 continue;
//             if(visit[newRow][newCol])
//                 continue;
//             visit[newRow][newCol] = true;
//             if(DFS(board, visit, newRow, newCol, str + board[newRow][newCol], word))
//             {
//                 visit[newRow][newCol] = false;
//                 return true;
//             }
//             visit[newRow][newCol] = false;
//         }
//         return false;
//     }
// };



class Solution
{
  public:
    struct TrieNode
    {
        vector<TrieNode *> children;
        bool isWord;
        TrieNode()
        {
            children = vector<TrieNode *>(26, NULL);
            isWord = false;
        }
        ~TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                if (children[i] != NULL)
                {
                    delete children[i];
                }
            }
        }
    };

    class Trie
    {
      public:
        TrieNode *root;
        Trie()
        {
            root = new TrieNode();
        }
        ~Trie()
        {
            delete root;
        }
        void insert(string word)
        {
            TrieNode *newRoot = root;
            for (int i = 0; i < word.size(); i++)
            {
                if (newRoot->children[word[i] - 'a'] == NULL)
                {
                    newRoot->children[word[i] - 'a'] = new TrieNode();
                }
                newRoot = newRoot->children[word[i] - 'a'];
            }
            newRoot->isWord = true;
        }
    };
    void DFS(vector<vector<char>> &board, vector<vector<bool>> &visit, TrieNode *newRoot, int row, int col, string str)
    {
        if (newRoot == NULL)
            return;
        if (newRoot->isWord)
        {
            newRoot->isWord = false;
            ans.push_back(str);
            //注意如果这里return的话，某些案例下会少答案，原因可想而知
        }
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if (newRow < 0 || newRow >= borderRow || newCol < 0 || newCol >= borderCol)
                continue;
            if (visit[newRow][newCol])
                continue;
            if (newRoot->children[board[newRow][newCol] - 'a'] == NULL)
                continue;
            visit[newRow][newCol] = true;
            DFS(board, visit, newRoot->children[board[newRow][newCol] - 'a'], newRow, newCol, str + board[newRow][newCol]);
            visit[newRow][newCol] = false;
        }
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        t = new Trie();
        borderRow = board.size();
        if (borderRow == 0 || words.size() == 0)
        {
            return ans;
        }
        borderCol = board[0].size();
        vector<vector<bool>> visit(borderRow, vector<bool>(borderCol, false));
        map<string, bool> check;
        string str = "";
        for(string s : words)
        {
            t->insert(s);
        }
        for (int r = 0; r < borderRow; r++)
        {
            for (int c = 0; c < borderCol; c++)
            {
                if (t ->root ->children[board[r][c] - 'a'] != NULL)
                {
                    visit[r][c] = true;
                    TrieNode *newRoot = t->root->children[board[r][c] - 'a'];
                    DFS(board, visit, newRoot, r, c, str + board[r][c]);
                    visit[r][c] = false;
                }
            }
        }
        return ans;
    }
    private:
      Trie *t;
      int dx[4] = {1, -1, 0, 0};
      int dy[4] = {0, 0, 1, -1};
      int borderRow;
      int borderCol;
      vector<string> ans;
};

int main()
{
    Solution s;
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}};
        //{{'a'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};/* {"a", "a"};*/
    vector<string> ans = s.findWords(board, words);
    for(auto a : ans)
    {
        cout << a << endl;
    }
    getchar();
    return 0;
}