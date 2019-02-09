// This unit test suite analyzes the fullDeckCount() function.

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


int main(int argc, char** argv)
{
    struct gameState GS;
    int cards[10] = { gardens, gardens, gardens, gold, village, curse, duchy, sea_hag, remodel, feast};
    int newGame = initializeGame(2, cards, 978, &GS);
    // check for various deck counts in different situations
    printf("%i\n", fullDeckCount(1,0,&GS));
    printf("%i\n", fullDeckCount(1,1,&GS));
    printf("%i\n", fullDeckCount(1,11,&GS));
    printf("%i\n", fullDeckCount(1,12,&GS));
    printf("%i\n", fullDeckCount(1,21,&GS));
    printf("%i\n", fullDeckCount(1,4,&GS));
    printf("%i\n", fullDeckCount(1,20,&GS));
    printf("%i\n", fullDeckCount(1,14,&GS));
    return 0;
}