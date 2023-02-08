//CS480 - Spring 2023
//Cody Crawford
//RedID:824167663
//Program 1
#define NCHILD 30 /* a-z, ', -, _, terminator of word */

class dictNode
{
    // Children nodes represent mapping to possible characters
    // of a word and the terminator character of a word.
    // Note the C string ends with a null \0 character.
    // Essentially, the index of each node in the next[] dictNode*
    // array is mapped to a particular valid character
    // or the terminator character.
    // For example, say index 0 is mapped
    // to character ‘a’, index 29 is mapped to the terminator
    // character. If the next character of the word is a, a new node
    // would be created and assigned to next[0]. Setting next[0]
    // from a null pointer to a new node means setting the next
    // character of the word to ‘a’.
    // Note all nodes in the next[] are initialized with a null
    // pointer.
    // After setting the last node corresponding to the last
    // character of the word, to terminate a word, you would
    // set the child node of the next [] of last character node
    // at the terminator index position to a new node, to indicate
    // the end of the word.
public:
    struct dictNode *children[NCHILD];
    dictNode()
    {
        for (int i = 0; i < 29; ++i)
        {
            this->children[i] = NULL;
        }
    }
};

static int length(const char *text)
{
    int i = 0;
    while (text[i] != '\0')
    {
        i++;
    }
    return i;
}

class TreeClass
{

public:
    dictNode *root;
    TreeClass()
    {
        this->root = NULL;
    }

    struct dictNode *createNode()
    {
        dictNode *temp = new dictNode();
        return temp;
    }

    // changed void to bool based on program rec
    bool add(const char *wordBeingInserted = nullptr)
    {
        bool result = false;
        // First get the length of text
        int textLength = length(wordBeingInserted);
        int index = 0;
        // Get the root node
        dictNode *head = this->root;
        for (int i = 0; i < textLength; ++i)
        {
            // Get the index
            index = wordBeingInserted[i] - 'a';
            if (head->children[index] == NULL)
            {
                // Adding a new node
                head->children[index] = createNode();
            }
            // Visiting the child node
            head = head->children[index];
        }
        if (head != NULL)
        {
            // This is the end of the string
            head->children[index] = createNode();
            result = true;
        }
        return result;
    }

    dictNode *findEndingNodeOfAStr(const char *strBeingSearched, struct dictNode *temp)
    {
        dictNode *head = temp;
        if (head == NULL)
        {
            // dictionary tree is empty, nothing to search
            return NULL;
        }
        int textLength = length(strBeingSearched);
        for (int i = 0; i < textLength; i++)
        {
            int index = strBeingSearched[i] - 'a';
            if (head->children[index] == NULL)
            {
                return NULL;
            }
            head = head->children[index];
        }
        return head;
    }

    void countWordsStartingFromANode(struct dictNode *temp, int &count)
    {
    }
};

