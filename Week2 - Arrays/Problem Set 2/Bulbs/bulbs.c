#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void convertMessageToBinary(string message);
void convertCharacterToBinaryAndPrint(int characterACIINum);

int main(void)
{
    string message = get_string("Message: ");
    convertMessageToBinary(message);
}

void convertMessageToBinary(string message)
{
    for (int i = 0; i < strlen(message); i++)
    {
        convertCharacterToBinaryAndPrint(message[i]);
    }
}

void convertCharacterToBinaryAndPrint(int characterACIINum)
{
    int bits[BITS_IN_BYTE] = {0, 0, 0, 0, 0, 0, 0, 0};
    int index = BITS_IN_BYTE - 1;

    while (characterACIINum)
    {
        bits[index] = characterACIINum % 2;
        index--;
        characterACIINum /= 2;
    }

    for (int i = 0; i < BITS_IN_BYTE; i++)
    {
        print_bulb(bits[i]);
    }

    printf("\n");
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
