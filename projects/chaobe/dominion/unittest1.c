// This unit test suite analyzes the getCost() function.

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void test1(struct gameState GS)
{
    int testCounter = 0;

    // each if statement tests that the card value matches with the appropriate cost
    // ex: card #1 (curse) should have a value of 0
    // testCounter variable adds up how many tests the function passes
    if (getCost(curse) == 0)
    {
        testCounter++;
    }

    if (getCost(estate) == 2)
    {
        testCounter++;
    }

    if (getCost(duchy) == 5)
    {
        testCounter++;
    }

    if (getCost(province) == 8)
    {
        testCounter++;
    }

    if (getCost(copper) == 0)
    {
        testCounter++;
    }

    if (getCost(silver) == 3)
    {
        testCounter++;
    }

    if (getCost(gold) == 6)
    {
        testCounter++;
    }

    if (getCost(adventurer) == 6)
    {
        testCounter++;
    }

    if (getCost(council_room) == 5)
    {
        testCounter++;
    }

    if (getCost(feast) == 4)
    {
        testCounter++;
    }

    if (getCost(gardens) == 4)
    {
        testCounter++;
    }

    if (getCost(mine) == 5)
    {
        testCounter++;
    }

    if (getCost(remodel) == 4)
    {
        testCounter++;
    }

    if (getCost(smithy) == 4)
    {
        testCounter++;
    }

    // note that this is just a plain village, not any other type (e.g. "blessed village")
    if (getCost(village) == 3)
    {
        testCounter++;
    }

    if (getCost(baron) == 4)
    {
        testCounter++;
    }

    if (getCost(great_hall) == 3)
    {
        testCounter++;
    }

    if (getCost(minion) == 5)
    {
        testCounter++;
    }

    if (getCost(steward) == 3)
    {
        testCounter++;
    }

    if (getCost(tribute) == 5)
    {
        testCounter++;
    }

    if (getCost(ambassador) == 3)
    {
        testCounter++;
    }

    if (getCost(cutpurse) == 4)
    {
        testCounter++;
    }

    if (getCost(embargo) == 2)
    {
        testCounter++;
    }

    if (getCost(outpost) == 5)
    {
        testCounter++;
    }

    if (getCost(salvager) == 4)
    {
        testCounter++;
    }

    if (getCost(sea_hag) == 4)
    {
        testCounter++;
    }

    if (getCost(treasure_map) == 4)
    {
        testCounter++;
    }

    // tests if card not listed returns -1 instead of actual value
    if (getCost(300) == -1)
    {
        testCounter++;
    }

    // if 28 tests pass, print success message
    if (testCounter == 28)
    {
        printf("All 28 tests for getCost() successfully PASSED");
    }

    // if fewer than 28 tests pass, print failure message
    else
    {
        printf("Test(s) for getCost() FAILED");
    }
}


int main(int argc, char** argv)
{
    struct gameState GS;
    test1(GS);

    return 0;
}