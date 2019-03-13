/*---------------------------------
 ** Author: Merry Caroline Purser
 ** February 9th, 2019
 ** The 2nd  cardtest, which
 ** tests the Smithy card
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
	
	printf("~~~Testing Smithy Card~~~\n");

	struct gameState state;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;

	int kCards[10] = {adventurer, smithy, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute};

	initializeGame(2, kCards, 4, &state);

	//Did player get +3 cards?
	int i = state.handCount[state.whoseTurn] + 3;
	cardEffect(smithy, choice1, choice2, choice3, &state, 0, NULL);
	int j = state.handCount[state.whoseTurn];

	if(i == j){
		printf("Passed: Hand count increment thrice.\n");
	} else {
		printf("Error: Hand count incrementing incorrectly.\n");
	}

	assert(cardEffect(smithy, choice1, choice2, choice3, &state, 0, NULL) == 0);
	printf("~~~End Testing Smithy Card~~~\n");

	return 0;
}
