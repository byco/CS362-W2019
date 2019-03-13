/*---------------------------------
 ** Author: Merry Caroline Purser
 ** February 9th, 2019
 ** The 3rd  cardtest, which
 ** tests the Village  card
 ** for dominion.c for
 ** CS362, Winter 2019, Assignment 3
 ** ---------------------------------*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main(int argc, char **argv) {
	
	printf("~~~Testing Village Card~~~\n");

	struct gameState state;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;

	int kCards[10] = {adventurer, smithy, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute};

	initializeGame(2, kCards, 4, &state);

	//Did player get +1 card?
	int i = state.handCount[state.whoseTurn]; //+1 for playing and getting to draw, -1 for discarding, net 0;
	cardEffect(village, choice1, choice2, choice3, &state, 0, NULL);
	int j = state.handCount[state.whoseTurn];

	if(i == j){
		printf("Passed: player hand count increments.\n");
	}else{
		printf("Error: player hand count not incrementing correctly.\n");
	}
	
	//Did player get +2 actions?
	int k = state.numActions + 2;
	cardEffect(village, choice1, choice2, choice3, &state, 0, NULL);
	int m = state.numActions;

	if(k == m){
		printf("Passed: player actions increments twice.\n");
	} else {
		printf("Error: player actions not incrementing correctly.\n");
	}

	assert(cardEffect(village, choice1, choice2, choice3, &state, 0, NULL) == 0);
	printf("~~~End Testing Village Card~~\n");

	return 0;
}
