#include "dictionary.h"

// Default constructor creates an empty dictionary
TreeClass::TreeClass()
{
    this->root = TreeClass::createNode();
}

// New node creation helper
dictNode* TreeClass::createNode()
{
    dictNode* temp = new dictNode();
    for (int i = 0; i < NCHILD; ++i)
    {
        temp->next[i] = nullptr;
    }
    return temp;
}

//     // changed void to bool based on program rec
//     bool add(const char *wordBeingInserted = nullptr)
//     {
//         bool result = false;
//         // First get the length of text
//         int textLength = length(wordBeingInserted);
//         int index = 0;
//         // Get the root node
//         dictNode *head = this->root;
//         for (int i = 0; i < textLength; ++i)
//         {
//             // Get the index
//             index = wordBeingInserted[i] - 'a';
//             if (head->children[index] == NULL)
//             {
//                 // Adding a new node
//                 head->children[index] = createNode();
//             }
//             // Visiting the child node
//             head = head->children[index];
//         }
//         if (head != NULL)
//         {
//             // This is the end of the string
//             head->children[index] = createNode();
//             result = true;
//         }
//         return result;
//     }

//     dictNode *findEndingNodeOfAStr(const char *strBeingSearched, struct dictNode *temp)
//     {
//         dictNode *head = temp;
//         if (head == NULL)
//         {
//             // dictionary tree is empty, nothing to search
//             return NULL;
//         }
//         int textLength = length(strBeingSearched);
//         for (int i = 0; i < textLength; i++)
//         {
//             int index = strBeingSearched[i] - 'a';
//             if (head->children[index] == NULL)
//             {
//                 return NULL;
//             }
//             head = head->children[index];
//         }
//         return head;
//     }

//     void countWordsStartingFromANode(struct dictNode *temp, int &count)
//     {
//     }
// };

void printRoot()
{

}
void printNode(struct dictNode* node)
{
    
}
