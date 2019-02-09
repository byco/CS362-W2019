// This unit test suite analyzes the numHandCards() function.

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void test3(struct gameState GS)
{
    // numHandCards checks the number of cards in each player's hand
    int testCounter = 0;

    int check = numHandCards(&GS);

    // player should draw 5 cards for opening hand (game just initialized), so should return 5
    if (check == 5)
    {
        testCounter++;
    }

    // if the test passes, print success message
    if (testCounter == 1)
    {
        printf("Test for numHandCards() successfully PASSED");
    }

    // if test fails, print failure message
    else
    {
        printf("Test(s) for numHandCards() FAILED");
    }
}


int main(int argc, char** argv)
{
    struct gameState GS;
    int cards[10] = { smithy, adventurer, estate, gold, village, curse, duchy, sea_hag, remodel, feast};
    int newGame = initializeGame(2, cards, 978, &GS);
    test3(GS);

    return 0;
}