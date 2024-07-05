#include <bits/stdc++.h>
using namespace std;

// returns vector<string> from src file
vector<string> get_array_from_file(string src)
{
    fstream file(src); // It tries to open the file specified by src using an fstream object named file.

    string word;
    vector<string> words;

    if (!file)
    {
        cerr << "\nCan't Open the File " << src << "Some Error Occurred...!\n";
        return words;
    }

    while (!file.eof())
    {                        // eof --> end of file, this implies that it continues to read until the end of the file is reached
        getline(file, word); // getline(file, line) reads a line from file and stores it in the word string.
        if (word.size())
            words.push_back(word);
        word = "\0"; // again initialized to empty string
    }

    return words;
}

// will search the pre "str" in every string of data (vector<string>)
vector<string> linear_search_pre(vector<string> data, string str)
{

    vector<string> results;

    auto start = chrono::high_resolution_clock::now();

    for (auto s : data)
    {
        bool match = true;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] != s[i])
            {
                match = false;
                break;
            }
        }
        if (match)
            results.push_back(s);
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cerr << "\033[32m\n"
         << results.size() << " results in " << double(duration.count() / double(1000000)) << " ms.\033[0m\n\n";

    return results;
}

// will return true if any exact match occured or return false
bool linear_search_exact(vector<string> data, string str)
{
    auto start = chrono::high_resolution_clock::now();

    bool found = false;
    for (auto s : data)
    {
        if (s == str)
        {
            found = true;
            break;
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cerr << "\033[32m\n"
         << found << " results in " << double(duration.count() / double(1000000)) << " ms.\033[0m\n\n";

    return false;
}

// KMP Matching

// Fills lps[] for given patttern pat[0....M-1]
void computeLPSArray(string pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Prints occurrences of txt[] in pat[]
int KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            // printf("Found pattern at index %d ", i - j);
            return i - j;
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return -1;
}

// will perform the universal search using KMP Algorithm
vector<string> search(vector<string> data, string pat)
{
    vector<string> results;

    auto start = chrono::high_resolution_clock::now();

    for (auto str : data)
    {
        if (KMPSearch(pat, str) != -1)
        {
            results.push_back(str);
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cerr << "\033[32m\n"
         << results.size() << " results in " << double(duration.count() / double(1000000)) << " ms.\033[0m\n\n";

    return results;
}