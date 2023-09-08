#include <cs50.h>
#include <stdio.h>

void makeAdjacentPyramid(int height);
void printSpace(int size);
void printBricks(int size);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    makeAdjacentPyramid(height);
}

void makeAdjacentPyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        printSpace(height - i);
        printBricks(i);
        printf("  ");
        printBricks(i);
        printf("\n");
    }
}

void printSpace(int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" ");
    }
}

void printBricks(int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("#");
    }
}