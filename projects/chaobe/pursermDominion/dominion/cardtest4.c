/*---------------------------------
 ** Author: Merry Caroline Purser
 ** February 9th, 2019
 ** The 4th  cardtest, which
 ** tests the great_hall  card
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
	
	printf("~~~Testing Great Hall Card~~~\n");

	struct gameState state;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;

	int kCards[10] = {adventurer, smithy, gardens, embargo, village, minion, mine, cutpurse, great_hall, tribute};

	initializeGame(2, kCards, 4, &state);
	int i = state.handCount[state.whoseTurn]; //hand count before card effect
	int k = state.numActions + 1; //state before card effect
	
	cardEffect(great_hall, choice1, choice2, choice3, &state, 0, NULL);


	int j = state.handCount[state.whoseTurn];
	int m = state.numActions;


	//Did player get +1 card?

	if((i  == j)){
		printf("Passed: Hand count incrementing correctly.\n");
	} else {
		printf("Error: Hand count incrementing incorrectly.\n");
	}
	

	//Did player get +1 actions?

	if(k == m){
		printf("Passed: Actions incrementing correctly.\n");
	} else {
		printf("Error: Actions incrementing incorrectly.\n");
	}


	assert(cardEffect(great_hall, choice1, choice2, choice3, &state, 0, NULL) == 0);
	printf("~~~End Testing Great Hall  Card~~~\n");

	return 0;
}
