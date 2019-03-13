/* Author: Merry Caroline Purser
 * February 26th, 2019
 * randomtestadventurer.c
 * tests the Adventurer card
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
	printf("~~~Random Tests: Adventurer Card~~~\n");
	
	srand(time(NULL));
	int tests = 250; //run this test with a random game 1000 times 
	int fault = 0;
	int i;
	for(i = 0; i < tests; i++){

		//Initialize a random game
		int players = rand() % (MAX_PLAYERS -1) + 2; //up to 4 playersi
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
		

		//Call cardEffect
		//cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, &bonus);
		cardEffect(adventurer, choice1, choice2, choice3, &state, 0, NULL);
		// Tests
		//After playing adventure card, player should recieve 2 more cards (treasure cards) and only 2 more cards.
		//discarding one and recieve two, this is a net positive of one. ( -1 + 2 = 1);
		if(state.handCount[player] != state2.handCount[player] + 1){
			printf("Error: Hand count not incrementing correctly.\n");
			fault++;
		}
		
		//player not correctly keeping treasure cards, the 2 new cards should be coins
		int newestCard = state.hand[player][state.handCount[player]-1];
		int newestCard2 = state.hand[player][state.handCount[player]-2];

		if(newestCard != copper && newestCard != silver && newestCard != gold){
			printf("Error: Newest card is not coins.\n");
			fault++;
		}

		if(newestCard2 != copper && newestCard2 != silver && newestCard2 != gold){
			printf("Error: 2nd newest card is not coins.\n");
			fault++;
		}

	}
	printf("Random tests passed: %d of %d\n", tests * 3 - fault, tests * 3); //the 3 is for the 3 different things being tested here.
	printf("~~~End Random Tests: Adventurer Card~~~\n");

	return 0;
}
