// This test suite analyzes the Great Hall card using random tests.
// The Great Hall card allows the player to draw one card and play another action.

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <time.h>


int main(int argc, char** argv)
{
    // seed so inputs can be random
    srand(time(NULL));
    int i;

    // need to make sure adventurer card will be available in game setup
    int cards[10] = {great_hall, sea_hag, village, smithy, great_hall, steward, gardens, council_room, embargo, outpost};
    // gs2 will get tested on
    struct gameState gs;
    struct gameState gs2;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int coin_bonus = 0;
    int newPlayer = 0;

    // test 20 times - should be enough times to spot a pattern
    for(i = 0; i < 20; i++) {

        // randomize the number of players and seed in each game
        // note that Dominion is intended for 2-6 players
        int players = rand() % 5 + 2;
        int seed = rand() % 1000;

        initializeGame(players, cards, seed, &gs2);

        memcpy(&gs, &gs2, sizeof(struct gameState));

        printf("gs hand: %i\n", gs.handCount[newPlayer]);
        printf("gs2 hand: %i\n", gs2.handCount[newPlayer]);

        cardEffect(great_hall, choice1, choice2, choice3, &gs2, handPos, &coin_bonus);

        // CHECK HAND COUNT
        // when great hall is played, the player gets another card
        // (so test hand and played hand should have same number of cards
        printf("gs hand: %i\n", gs.handCount[newPlayer]);
        printf("gs2 hand: %i\n", gs2.handCount[newPlayer]);

        if(gs.handCount[newPlayer] == gs2.handCount[newPlayer])
        {
            printf("Hand Count Test PASSED\n");
        }
        else
        {
            printf("Hand Count Test FAILED\n");
        }
        printf("-------\n");

        // check if player used Great Hall card - card count should go up
        if(gs.playedCardCount == gs2.playedCardCount)
        {
            printf("Played Card Test PASSED %i %i\n", gs.playedCardCount, gs2.playedCardCount);
        }
        else
        {
            printf("Played Card FAILED %i %i\n", gs.playedCardCount, gs2.playedCardCount);
        }
        printf("-------\n");


        // check if new action given to player

        if(gs.numActions + 1 == gs2.numActions)
        {
            printf("Actions Test PASSED\n");
        }
        else
        {
            printf("Actions Test FAILED\n");
        }
        printf("-------\n");


    }
    return 0;
}
