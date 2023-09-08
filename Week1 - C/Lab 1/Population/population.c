#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // TODO: Prompt for start size
    int initialPopulationSize;
    do
    {
        initialPopulationSize = get_int("Please enter initial population size of llamas: ");
    }
    while (initialPopulationSize < 9);

    // TODO: Prompt for end size
    int finalPopulationSize;
    do
    {
        finalPopulationSize = get_int("Please enter final population size of llamas: ");
    }
    while (finalPopulationSize < initialPopulationSize);

    // TODO: Calculate number of years until we reach threshold
    int bornLamasNum;
    int diedLamasNum;
    int currentPopulationSize = initialPopulationSize;
    int numberOfYears = 0;

    while (currentPopulationSize < finalPopulationSize)
    {
        numberOfYears++;
        bornLamasNum = currentPopulationSize / 3;
        diedLamasNum = currentPopulationSize / 4;
        currentPopulationSize += bornLamasNum - diedLamasNum;
    }

    // TODO: Print number of years
    printf("Years: %i\n", numberOfYears);
}
