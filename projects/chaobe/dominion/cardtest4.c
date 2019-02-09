// This test suite analyzes the steward card.

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

    int cards[10] = { minion, steward, gardens, gold, village, curse, duchy, sea_hag, remodel, feast};
    initializeGame(2, cards, 978, &GS);

    // copy GS to GS2 (GS2 will be the control, unchanged while GS is tested with playing steward)
    memcpy(&GS2,&GS,sizeof(struct gameState));

    printf("after starting game: %i and %i\n", GS.handCount[GS.whoseTurn], GS2.handCount[GS2.whoseTurn]);

    // now play steward to see effect on hand count
    cardEffect(steward,0,-1,-1,&GS,0,0);
    printf("after playing steward - choice1 == 0: %i and %i\n", GS.handCount[GS.whoseTurn], GS2.handCount[GS2.whoseTurn]);
    cardEffect(steward,1,-1,-1,&GS,0,0);
    printf("after playing steward - choice1 == 1: %i and %i\n", GS.handCount[GS.whoseTurn], GS2.handCount[GS2.whoseTurn]);
    cardEffect(steward,2,-1,-1,&GS,0,0);
    printf("after playing steward - choice1 == 2: %i and %i\n", GS.handCount[GS.whoseTurn], GS2.handCount[GS2.whoseTurn]);


    return 0;
}