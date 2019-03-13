/* Author: Merry Caroline Purser
 * February 26th, 2019
 * randomtestcard1.c
 * tests the Smithy card
 * for dominion.c for
 * CS362, Winter 2019, Assignment 4
 * ---------------------------------*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv) {
        printf("~~~Random Tests: Smithy  Card~~~\n");
	srand(time(NULL));
	int tests = 750; 
	int fault = 0;
	int i;
	for(i = 0; i < tests; i++){
		//Initialize a random game
		int players = rand() % (MAX_PLAYERS -1) +2;
		int randNum = rand() % 100;
		if(randNum == 0){
			randNum = 1;
		}
		struct gameState state;
		int kCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

		initializeGame(players, kCards, randNum, &state);

		int player = rand() % players;
		state.whoseTurn = player;
		state.deckCount[player] = rand() % MAX_DECK;
		state.discardCount[player] = rand() % MAX_DECK;
		state.handCount[player] = rand() % MAX_HAND;
		if(state.handCount[player] == 0){
			state.handCount[player] = 1;
		}

		int choice1 = 0;
		int choice2 = 0;
		int choice3 = 0;

		struct gameState state2;
		memcpy(&state2, &state, sizeof(struct gameState));

		cardEffect(smithy, choice1, choice2, choice3, &state, 0, NULL);

		//Tests
		//test hand count: After playing Smithy, player should recieve 3 more cards and discard Smithy.
		//thus hand count should be grow by two ( 3 - 1 = 2 ).
		if(state.handCount[player] != state2.handCount[player] + 2){
			printf("Error: Hand count not incrementing correctly.\n");
			fault++;
		}

	}
		printf("Random tests passed: %d of %d\n", tests - fault, tests);
		printf("~~~End Random Tests: Smithy Card~~~\n");
	        return 0;
	}
