#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
    }
};

class Trie
{
public:
    int total_nodes;
    int total_words;
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string str);
    void remove(string str);
    bool _remove(TrieNode *current, string str, int index);
    TrieNode *search_exact(string str);
    vector<string> search_pre(string str);
    void draw(TrieNode *current, int depth);
};

// will insert the string into the Trie
void Trie::insert(string str)
{
    TrieNode *current = root;

    for (int i = 0; i < str.size(); ++i)
    {
        char ch = str[i];
        if (current->children.find(ch) != current->children.end())
        {
            current = current->children[ch];
        }
        else
        {
            current->children.insert(make_pair(ch, new TrieNode()));
            current = current->children[ch];
        }
    }

    current->isEndOfWord = true;
}

// will search the exact str matching in the Trie
TrieNode *Trie::search_exact(string str)
{
    TrieNode *current = root;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < str.size(); ++i)
    {
        char ch = str[i];
        if (current->children.find(ch) != current->children.end())
        {
            current = current->children[ch];
        }
        else
        {
            return NULL;
        }
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cerr << "\033[32m\n"
         << current->isEndOfWord << " results in " << double(duration.count() / double(1000000)) << " ms.\033[0m\n\n";

    // as this is the exact match, we need to check whether this is the end of the word or not
    return current->isEndOfWord ? current : NULL;
}

// it will give all the remaining nodes from current node to end of the word
// eg : pre : 123 --> 1234, 12345, 1234563, 123, 1239...........
void get_words_dfs(TrieNode *current, string pre, vector<string> &results)
{
    if (current == NULL)
    {
        return;
    }
    if (current->isEndOfWord)
    {
        results.push_back(pre);
    }
    // traversing all the children from the current node
    for (auto it : current->children)
    {
        get_words_dfs(it.second, (pre + it.first), results);
    }
}

// search the prefix str in all the lines of data
vector<string> Trie::search_pre(string str)
{
    auto start = chrono::high_resolution_clock::now();

    TrieNode *current = root;
    vector<string> results;

    for (int i = 0; i < str.size(); ++i)
    {
        char ch = str[i];
        if (current->children.find(ch) != current->children.end())
        {
            current = current->children[ch];
        }
        else
        {
            return results;
        }
    }

    get_words_dfs(current, str, results);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cerr << "\033[32m\n"
         << results.size() << " results in " << double(duration.count() / double(1000000)) << " ms.\033[0m\n\n";

    return results;
}

// Delete a string
void Trie::remove(string str)
{
    _remove(root, str, 0);
}

bool Trie::_remove(TrieNode *current, string str, int index)
{
    if (index == str.length())
    {
        // End of the word ?
        if (!current->isEndOfWord)
        {
            return false; // word doesn't exist.
        }
        current->isEndOfWord = false; // making it false indirectly removes the str

        // if no more children
        return current->children.size() == 0; // true?
    }

    char ch = str[index];

    if (!current->children[ch])
    {
        return false; // word doesn't exist.
    }

    bool shouldDeleteCurrentNode = _remove(current->children[ch], str, index + 1);

    // after recursion
    if (shouldDeleteCurrentNode)
    {
        current->children.erase(ch);
        return current->children.size() == 0; // true ?
    }

    return false;
}