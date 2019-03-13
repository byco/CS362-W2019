/* Author: Merry Caroline Purser
 * February 26th, 2019
 * randomtestcard2.c
 * tests the Great Hall card
 * for dominion.c for
 * CS362, Winter 2019, Assignment 4
 *  ---------------------------------*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv) {
        printf("~~~Random Tests: Great Hall Card~~~\n");
	srand(time(NULL));
	int tests = 750;
	int fault = 0;
	int i;

	for(i = 0; i < tests; i++){
		//Initialize random game
		int players = rand() % (MAX_PLAYERS-1) +2; //up to 4 players
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

		//a way to remember initial state values
		struct gameState state2;
		memcpy(&state2, &state, sizeof(struct gameState));

		//call cardEffect
		cardEffect(great_hall, choice1, choice2, choice3, &state, 0, NULL);

		//Tests
		//Did player get +1 card?
		if(state.handCount[state.whoseTurn] != state2.handCount[state.whoseTurn]){
			printf("Error: hand count not incrementing correctly.");
			fault++;
		}

		//Did player get +1 actions?
		if(state.numActions != state2.numActions + 1){
			printf("Error: actions not incrementing correctly.");
			fault++;
		}

	}

	printf("Random tests passed: %d or %d\n", tests - fault, tests); 
	printf("~~~End Random Tests: Great Hall  Card~~~\n");
	        return 0;
	}
