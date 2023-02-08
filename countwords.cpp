// CS480 - Spring 2023
// Cody Crawford
// RedID:824167663
// Program 1
#include "dictionary.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " vocabulary_file text_file" << endl;
        return 1;
    }

    TreeClass tree;

    // read in the vocabulary file
    ifstream vocabFile(argv[1]);
    if (!vocabFile.is_open())
    {
        cerr << "Error: Failed to open vocabulary file " << argv[1] << endl;
        return 2;
    }
    string word;
    while (vocabFile >> word)
    {
        tree.add(word.c_str());
    }
    vocabFile.close();

    // read in the text file
    ifstream textFile(argv[2]);
    if (!textFile.is_open())
    {
        cerr << "Error: Failed to open text file " << argv[2] << endl;
        return 3;
    }
    while (textFile >> word)
    {
        dictNode *node = tree.findEndingNodeOfAStr(word.c_str());
        if (node == nullptr)
        {
            cout << word << " not found in vocabulary tree" << endl;
            continue;
        }
        int count = 0;
        tree.countWordsStartingFromANode(node, count);
        cout << word << " appears " << count << " times" << endl;
    }
    textFile.close();

    return 0;
}