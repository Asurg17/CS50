#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isNumber(string str);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (!isNumber(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string plainText = get_string("plaintext: ");
    int textSize = strlen(plainText);
    char ciphertext[textSize];
    strcpy(ciphertext, plainText);

    for (int i = 0; i < textSize; i++)
    {
        if (isalpha(ciphertext[i]))
        {
            if (isupper(ciphertext[i]))
            {
                ciphertext[i] = 'A' + ((ciphertext[i] - 'A' + key) % 26);
            }
            else
            {
                ciphertext[i] = 'a' + ((ciphertext[i] - 'a' + key) % 26);
            }
        }
    }

    printf("ciphertext: %s\n", ciphertext);
}

bool isNumber(string str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }

    return true;
}