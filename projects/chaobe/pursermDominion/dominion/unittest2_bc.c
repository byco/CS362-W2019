// This unit test suite analyzes the isGameOver() function.

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void test2(struct gameState GS)
{
    // isGameOver checks that the Dominion end game rules are enforced correctly
    int testCounter = 0;

    int check = isGameOver(&GS);

    // game should not be over yet (just initialized), so should return 0
    if (check == 0)
    {
        testCounter++;
    }

    // if the test passes, print success message
    if (testCounter == 1)
    {
        printf("Test for isGameOver() successfully PASSED");
    }

    // if test fails, print failure message
    else
    {
        printf("Test(s) for isGameOver() FAILED");
    }
}


int main(int argc, char** argv)
{
    struct gameState GS;
    int cards[10] = { smithy, adventurer, estate, gold, village, curse, duchy, sea_hag, remodel, feast};
    int newGame = initializeGame(2, cards, 978, &GS);
    test2(GS);

    return 0;
}