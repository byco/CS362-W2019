/*---------------------------------
 * Author: Merry Caroline Purser
 * February 9th, 2019
 * The first cardtest, which
 * tests the Adventurer card
 * for dominion.c for
 * CS362, Winter 2019, Assignment 3
 * ---------------------------------*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main(int argc, char **argv){
	
	printf("~~~Testing Adventurer Card~~~\n");

	struct gameState state;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;

	int kCards[10]  = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, kCards, 4, &state);

	//After playing adventure card, player should receive 2 more cards (treasure cards) and only 2 more cards.
	int i = state.handCount[0] + 1; //discard one (-1) and receive 2 (+2) is a net positive of one.
	cardEffect(adventurer, choice1, choice2, choice3, &state, 0, NULL);
	int j = state.handCount[0];

	if(i == j){
		printf("Passed: hand count incremented correctly.\n");
	} else {
		printf("Error: hand count incrementing incorrectly.\n");
	}

	assert(cardEffect(adventurer, choice1, choice2, choice3, &state, 0, NULL) == 0);
	printf("~~~End Testing Adventurer Card~~~\n");
	return 0;
}


