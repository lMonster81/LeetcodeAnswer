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

class Trie
{
    struct TrieNode
    {
        bool isWord;
        vector<TrieNode *> children;
        TrieNode()
        {
            isWord = false;
            children = vector<TrieNode *>(26, NULL);
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

    private:
      TrieNode *root;

    public:
      Trie()
      {
          root = new TrieNode();
      }
      ~Trie()
      {
          delete root;
      }

      bool find(string word, TrieNode *&newRoot)
      {
          for (int i = 0; i < word.size(); i++)
          {
              if (newRoot->children[word[i] - 'a'] == NULL)
              {
                  return false;
              }
              newRoot = newRoot->children[word[i] - 'a'];
          }
          return true;
    }

    void insert(string word)
    {
        TrieNode* newRoot = root;
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


    bool search(string word)
    {
        TrieNode *newRoot = root;
        return (find(word, newRoot) && newRoot->isWord);
    }

    bool startsWith(string prefix)
    {
        TrieNode *newRoot = root;
        return find(prefix, newRoot);
    }
};

int main()
{
    Trie t;
    t.insert("apple");
    cout << t.search("apple") << endl;
    cout << t.search("app") << endl;
    cout << t.startsWith("app") << endl;
    getchar();
}