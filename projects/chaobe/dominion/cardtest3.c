// This test suite analyzes the great hall card.

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>


int main(int argc, char** argv)
{
    struct gameState GS;
    struct gameState GS2;

    // Test hand count before game is initialized
    printf("before game: %i and %i\n", GS.handCount[GS.whoseTurn], GS2.handCount[GS2.whoseTurn]);

    int cards[10] = { minion, great_hall, gardens, gold, village, curse, duchy, sea_hag, remodel, feast};
    initializeGame(2, cards, 978, &GS);

    // copy GS to GS2 (GS2 will be the control, unchanged while GS is tested with playing great hall)
    memcpy(&GS2,&GS,sizeof(struct gameState));

    printf("after starting game: %i and %i\n", GS.handCount[GS.whoseTurn], GS2.handCount[GS2.whoseTurn]);

    // also check actions before card is played
    printf("actions: %i and %i\n",GS.numActions, GS2.numActions);
    // now play great hall to see effect on hand count
    cardEffect(great_hall,-1,-1,-1,&GS,0,0);
    printf("after playing great hall: %i and %i\n", GS.handCount[GS.whoseTurn], GS2.handCount[GS2.whoseTurn]);

    // see effect on actions
    printf("actions: %i and %i\n",GS.numActions, GS2.numActions);


    return 0;
}