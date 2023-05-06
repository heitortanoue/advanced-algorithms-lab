#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generateWords(string word, std::string::size_type index, vector<string> &words)
{
    if (index == word.length() - 1)
    { // caso base
        words.push_back(word);
        return;
    }

    generateWords(word, index + 1, words);
    word.insert(index + 1, " ");
    generateWords(word, index + 2, words);
    word.erase(index + 1, 1);
}

int main()
{
    string word;

    while (cin >> word)
    {
        vector<string> words;
        generateWords(word, 0, words);

        for (string w : words)
        {
            cout << w << endl;
        }
        cout << endl;
    }

    return 0;
}
