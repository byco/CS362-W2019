// This test suite analyzes the adventurer card using random tests.
// The Adventurer card reveals cards from deck until 2 Treasure cards are found.
// The Treasure cards are put into player's hand and other cards found are discarded.

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
    int cards[10] = {adventurer, sea_hag, village, smithy, great_hall, steward, gardens, council_room, embargo, outpost};
    // gs2 will get tested on
    struct gameState gs;
    struct gameState gs2;

    // test 20 times - should be enough times to spot a pattern
    for(i = 0; i < 20; i++) {
        int choice1 = 0;
        int choice2 = 0;
        int choice3 = 0;
        int handPos = 0;
        int coin_bonus = 0;
        int newPlayer = 0;

        // randomize the number of players and seed in each game
        // note that Dominion is intended for 2-6 players
        int players = rand() % 5 + 2;
        int seed = rand() % 1000;

        initializeGame(players, cards, seed, &gs2);

        memcpy(&gs, &gs2, sizeof(struct gameState));

        printf("gs hand: %i\n", gs.handCount[newPlayer]);
        printf("gs2 hand: %i\n", gs2.handCount[newPlayer]);

        cardEffect(adventurer, i, choice2, choice3, &gs2, handPos, &coin_bonus);

        // after playing adventurer, gs2's hand count should go up by 1 (discarded 1 adventurer card, picked up 2 treasure cards)
        // perhaps it's possible to not get 2 Treasure cards but it should be ok at beginning of game
        printf("gs hand: %i\n", gs.handCount[newPlayer]);
        printf("gs2 hand: %i\n", gs2.handCount[newPlayer]);
        if(gs.handCount[newPlayer] + 1 == gs2.handCount[newPlayer])
        {
            printf("Hand Count Test PASSED\n");
        }
        else
        {
            printf("Hand Count Test FAILED\n");
        }
        printf("-------\n");
    }
    return 0;
}
