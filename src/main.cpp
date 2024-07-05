#include <bits/stdc++.h>
#include "trie.cpp"
#include "utils.cpp"
using namespace std;

// argc : Argument Count
// It holds the number of command-line arguments passed to the program, including the program's name itself. For example, if you run your
// program with ./myprogram arg1 arg2, argc would be 3 (one for the program name and two for the arguments arg1 and arg2).

// argv : Argument Vector
// It is an array of strings (character pointers) representing the actual arguments passed to the program. argv[0] is the program's name,
//  argv[1] is the first argument, argv[2] is the second argument, and so on.

int main(int argc, char **argv)
{
    string filename;
    Trie T;
    vector<string> data;

    // checking whether file is in the command line input or not
    if (argc > 1)
    {
        filename = argv[1];
        data = get_array_from_file(filename);
    }
    // if file if not present in command line input, then take it as an input from the user
    else
    {
        cout << "Enter File name to load data from. ( music | movies ) :\n";
        cin >> filename;
        // cerr --> standard error stream
        cerr << "Loading ...\n";
        data = get_array_from_file("../assets/" + filename + ".txt");
        cerr << "Done.\n";
    }

    // example data : data = {"Hello, World!", "This is a test file.", "It contains multiple lines."}
    for (string word : data)
    {
        // cout << word << "\n";
        T.insert(word);
    }

    int choice;
    // If pattern given in command line arguments
    if (argc > 2)
    {
        string pattern = argv[2]; // if you get the input from command line, directly search the pattern and return
        for (string w : search(data, pattern))
        {
            cout << w << "\n";
        }
        return 0;
    }

    do
    {
        cout << "------------------------\n";
        cout << "MENU\n";
        cout << "1. Exact Search.\n";
        cout << "2. Prefix Search.\n";
        cout << "3. Universal Search.\n";
        cout << "0. Exit.\n";

        cin >> choice;
        // After cin >> choice;, there might be a leftover newline character ('\n') in the input buffer because pressing Enter after entering the value for choice generates this newline character. getchar(); is used to read and discard this leftover newline character ensuring that the input buffer is clean for the next input operation.
        getchar();

        string pattern;

        if (choice)
        {
            cout << "Enter Search Text (leave empty to list all) : ";
            getline(cin, pattern);
        }

        switch (choice)
        {
        case 1:
            if (T.search_exact(pattern))
            {
                cout << "String Exists...\n";
            }
            else
            {
                cout << "Not Found...\n";
            }
            break;
        case 2:
            for (string w : T.search_pre(pattern))
            {
                cout << w << "\n";
            }
            break;

        case 3:
            for (string w : search(data, pattern))
            {
                cout << w << "\n";
            }
            break;

        default:
            break;
        }

        cout << "\n\npress any key to continue.";
        getchar();
        system("cls");

    } while (choice);

    return 0;
}