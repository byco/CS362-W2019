/*-------------------------------
 * Author: Merry Caroline Purser
 * February 5th, 2019
 * The third unit test to test
 * updateCoins function in dominion.c for
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
	state.coins = 0;
	state.handCount[0] = 10;

	printf("~~~Testing updateCoins~~~\n");
	

	//Test copper
	int i;
	for(i = 0; i < 10; i++){
		state.hand[0][i] = copper;
	}

	updateCoins(0, &state, 0);

	if(state.coins == 10){
		printf("Passed: Copper in updateCoins.\n");
	}
	
	//Test silver
	for(i = 0; i < 10; i++){
		state.hand[0][i] = silver;
	}

	updateCoins(0, &state, 0);

	if(state.coins == 20){
		printf("Passed: Silver in updateCoins.\n");
	}

	//Test gold
	for(i = 0; i < 10; i++){
		state.hand[0][i] = gold;
	}

	updateCoins(0, &state, 0);

	if(state.coins == 30){
		printf("Passed: Gold in updateCoins.\n");
	}
	
	printf("~~~End Testing updateCoins~~~\n");
	return 0;

 }
