/*-------------------------------
 * Author: Merry Caroline Purser
 * February 5th, 2019
 * The second unit test to test
 * numBuys function in dominion.c for
 * CS362, Winter 2019, Assignment 3
 * ---------------------------------------*/

 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <assert.h>
 #include <math.h>
 #include <stdlib.h>
 #include "rngs.h"


int main(int argc, char** argv) {

	struct gameState state;
	printf("~~~Testing buyCard Function~~~\n");

	//Player has buys and coins
        state.numBuys = 2;
        state.coins = 10;
	
        if(buyCard(2, &state) == 0){
		printf("Passed: Player able to make purchase given coins and buys.\n");
	}else{
		printf("Error: Player unable to make purchases with sufficient coins and buys.\n");
		printf("Or, numBuys return -1 erroneously for other reason.\n");
	}

	//Player does not have enough coins      
	state.coins = 0;
	if(buyCard(2, &state) == -1){
	   	printf("Passed: Player cannot purchase cards with insufficient coins.\n");
		printf("numBuys returned -1.\n");
	}else{
		printf("Error: Player does not have enough coins but can buyCard.\n");
	}

	//not a test, just using last buy in current state set-up
	state.coins = 10;
	buyCard(2, &state);
	                                                        


	//Player does not have buys left
	if(buyCard(2, &state) == -1){
		printf("Passed: Player cannot purchase cards if they do not have buys.\n");
		printf("numBuys returned -1.\n");
	}else{
		printf("Error: Player has no buys but can buyCard.\n");
	}

	printf("~~End Testing buyCard Function~~~\n");
	return 0;

 }

