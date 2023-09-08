#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calculateTextGrade(string text);
int countLetters(string text);
int countWords(string text);
int countSentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int grade = calculateTextGrade(text);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Coleman-Liau index
// Formula: index = 0.0588 * L - 0.296 * S - 15.8
// L is the average number of letters per 100 words in the text
// S is the average number of sentences per 100 words in the text
int calculateTextGrade(string text)
{
    int lettersCount = countLetters(text);
    int wordsCount = countWords(text);
    int sentencesCount = countSentences(text);

    int grade = round((0.0588 * lettersCount / wordsCount * 100.0) - (0.296 * sentencesCount / wordsCount * 100.0) - 15.8);

    return grade;
}

int countLetters(string text)
{
    int lettersCount = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            lettersCount++;
        }
    }

    return lettersCount;
}

int countWords(string text)
{
    int wordsCount = 0;
    int textLength = strlen(text);
    bool isNewWord = false;

    for (int i = 0; i < textLength; i++)
    {
        if (isalpha(text[i]))
        {
            isNewWord = true;
        }
        else if (isblank(text[i]))
        {
            if (isNewWord)
            {
                wordsCount++;
            }
            isNewWord = false;
        }

        // Need to count last word
        if (i == textLength - 1)
        {
            if (isNewWord)
            {
                wordsCount++;
            }
        }
    }

    return wordsCount;
}

int countSentences(string text)
{
    int sentencesCount = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentencesCount++;
        }
    }

    return sentencesCount;
}
