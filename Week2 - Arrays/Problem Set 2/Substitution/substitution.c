#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int CHAR_NUM_IN_ALPHABET = 26;

bool isKeyValid(string key);
void encodeText(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (!isKeyValid(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    encodeText(plaintext, argv[1]);
}

bool isKeyValid(string key)
{
    // Check length
    if (strlen(key) != 26)
    {
        return false;
    }

    int arr[CHAR_NUM_IN_ALPHABET] = {0};

    // Check if all characters are alphbetic
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
        arr[tolower(key[i]) - 'a']++;
    }

    // Check if key contains repeating letters
    for (int i = 0; i < CHAR_NUM_IN_ALPHABET; i++)
    {
        if (arr[i] == 0 || arr[i] > 1)
        {
            return false;
        }
    }

    return true;
}

void encodeText(string plaintext, string key)
{
    int textSize = strlen(plaintext);
    char ciphertext[textSize];
    strcpy(ciphertext, plaintext);

    for (int i = 0; i < textSize; i++)
    {
        if (isalpha(ciphertext[i]))
        {
            if (isupper(ciphertext[i]))
            {
                ciphertext[i] = toupper(key[ciphertext[i] - 'A']);
            }
            else
            {
                ciphertext[i] = tolower(key[ciphertext[i] - 'a']);
            }
        }
    }

    printf("ciphertext: %s\n", ciphertext);
}
