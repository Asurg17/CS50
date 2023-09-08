// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool isUppercaseIncluded = false;
    bool isLowercaseIncluded = false;
    bool isNumberIncluded = false;
    bool isSymbolIncluded = false;

    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            isUppercaseIncluded = true;
        }
        else if (islower(password[i]))
        {
            isLowercaseIncluded = true;
        }
        else if (isdigit(password[i]))
        {
            isNumberIncluded = true;
        }
        else if (ispunct(password[i]))
        {
            isSymbolIncluded = true;
        }
    }

    return isUppercaseIncluded && isLowercaseIncluded && isNumberIncluded && isSymbolIncluded;
}
