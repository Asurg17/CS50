#include <cs50.h>
#include <stdio.h>

string getCardClass(long cardNumber);
bool isCardNumberLengthValid(int cardNumberSize);
bool isChecksumValid(int checksum);
bool isVisa(long cardNumber, int length);
bool isMasterCard(long cardNumber, int length);
bool isAmericanExpress(long cardNumber, int length);

int main(void)
{
    long cardNumber;
    do
    {
        cardNumber = get_long("Number: ");
    }
    while (cardNumber < 0);

    printf("%s\n", getCardClass(cardNumber));
}

string getCardClass(long cardNumber)
{
    long cardNumberIter = cardNumber;
    int length = 0;
    int checksum = 0;
    int currentDigit;

    while (cardNumberIter > 0)
    {
        currentDigit = cardNumberIter % 10;
        cardNumberIter = cardNumberIter / 10;
        length++;

        if (length % 2 == 0)
        {
            currentDigit = currentDigit * 2;
            checksum += currentDigit % 10 + currentDigit / 10;
        }
        else
        {
            checksum += currentDigit;
        }
    }

    if (isCardNumberLengthValid(length))
    {
        if (isChecksumValid(checksum))
        {
            if (isVisa(cardNumber, length))
            {
                return "VISA";
            }
            else if (isMasterCard(cardNumber, length))
            {
                return "MASTERCARD";
            }
            else if (isAmericanExpress(cardNumber, length))
            {
                return "AMEX";
            }
        }
    }

    return "INVALID";
}

bool isCardNumberLengthValid(int cardNumberSize)
{
    if (cardNumberSize != 13 && cardNumberSize != 15 && cardNumberSize != 16)
    {
        return false;
    }
    return true;
}

bool isChecksumValid(int checksum)
{
    if (checksum % 10 == 0)
    {
        return true;
    }
    return false;
}

// Visa uses 13 and 16 digit numbers
// All Visa numbers start with 4
bool isVisa(long cardNumber, int length)
{
    int prefix = 0;
    if (length == 13)
    {
        prefix = cardNumber / 1000000000000;
    }
    else if (length == 16)
    {
        prefix = cardNumber / 1000000000000000;
    }

    if (prefix == 4)
    {
        return true;
    }

    return false;
}

// MasterCard uses 16 digit numbers
// Most MasterCard numbers start with 51, 52, 53, 54, or 55
bool isMasterCard(long cardNumber, int length)
{
    if (length == 16)
    {
        int prefix = cardNumber / 100000000000000;
        if (prefix == 51 || prefix == 52 || prefix == 53 || prefix == 54 || prefix == 55)
        {
            return true;
        }
    }
    return false;
}

// American Express uses 15 digit numbers
// All American Express numbers start with 34 or 37
bool isAmericanExpress(long cardNumber, int length)
{
    if (length == 15)
    {
        int prefix = cardNumber / 10000000000000;
        if (prefix == 34 || prefix == 37)
        {
            return true;
        }
    }
    return false;
}