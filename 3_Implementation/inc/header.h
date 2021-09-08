#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "assert.h"

int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int greater(char c1, char c2)
{
    if (c1 == c2)
    {
        return -1;
    }
    else if (c1 == 'r' && c2 == 's')
    {
        return 1;
    }
    else if (c2 == 'r' && c1 == 's')
    {
        return 0;
    }
    else if (c1 == 'p' && c2 == 'r')
    {
        return 1;
    }
    else if (c2 == 'p' && c1 == 'r')
    {
        return 0;
    }

    else if (c1 == 's' && c2 == 'p')
    {
        return 1;
    }
    else if (c2 == 's' && c1 == 'p')
    {
        return 0;
    }
}

int main()
{
     int playerScore = 0, compScore = 0, temp;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};
     for (int i = 0; i < 3; i++)
    {
        // Take player input
        scanf("%d", &temp);
        getchar();
        playerChar = dict[temp - 1];

        //computer generate
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];

        // compater character and increment the score
        if (greater(compChar, playerChar) == 1)
        {
            compScore++;
        }
        else if (greater(compChar, playerChar) == -1)
        {
            compScore++;
            playerScore++;
        }
        else
        {
            playerScore++;
        }

    }

     assert(greater(playerScore,compScore)== 1);
      printf("computer got it");
     assert(greater(playerScore,compScore)== -1);
      printf("draw");
     assert(greater(playerScore,compScore)== 0);
      printf("player got it");

}