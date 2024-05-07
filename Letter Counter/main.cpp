#include <iostream>

#define LOG(x) std::cout << x << std::endl
#define MAX_WORD_LENGTH 32


static int checkForDuplicates(char letter, char letters[MAX_WORD_LENGTH][2])
{
    for (int i = 0; i < MAX_WORD_LENGTH && letters[i][0] != '\0'; i++)
    {
        if (letter == letters[i][0])
        {
            return i;
        }
    }

    return -1;
}

int main(void)
{
    char word[MAX_WORD_LENGTH];
    int newLetterPosition = 0;

    //               letter     count
    char letters[MAX_WORD_LENGTH][2] = {};

    LOG("Enter Word");
    std::cin.getline(word, MAX_WORD_LENGTH);

    for (int i = 0; word[i] != '\0'; i++)
    {
        int duplicatePosition = checkForDuplicates(word[i], letters);

        if (duplicatePosition != -1)
        {
            letters[duplicatePosition][1] += 1;
        }
        else
        {
            letters[newLetterPosition][0] = word[i];
            letters[newLetterPosition][1] = 1;
            newLetterPosition += 1;
        }
    }

    LOG(" ");
    LOG("Letter counts:");
    for (int i = 0; i < newLetterPosition; i++)
    {
        LOG(letters[i][0] << ": " << (int)letters[i][1]);
    }

    return 0;
}
