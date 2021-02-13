#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

bool allZ(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] != 'z')
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    // 97 - 122
    string word = "a";
    string secretWord = "helloworld";
    int firstChar;
    int index;

    while (true)
    {
        while (!allZ(word))
        {
            if (word == secretWord)
            {
                cout << "Secret word is " << word << endl;
                return 0;
            }

            firstChar = word.length() - 1;
            if (word[firstChar] != 'z')
            {
                word[firstChar] += 1;
            }
            else
            {
                if (firstChar == 0)
                {
                    continue;
                }
                else
                {
                    index = firstChar - 1;
                }

                if (word[index] == 'z')
                {
                    while (word[index] == 'z')
                    {
                        index -= 1;
                    }
                    for (int i = firstChar; i > index; i--)
                    {
                        word[i] = 'a';
                    }
                    word[index] += 1;
                }
                else
                {
                    word[index] += 1;
                    word[firstChar] = 'a';
                }

            }

            cout << word << endl;

        }
        for (int i = 0; i < word.length(); i++)
        {
            word[i] = 'a';
        }
        word += "a";
        cout << word << endl;
    }

}