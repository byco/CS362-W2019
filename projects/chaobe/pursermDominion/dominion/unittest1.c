/*-------------------------------------------
 * Author: Merry Caroline Purser
 * February 5th, 2019
 * The first unit test to test
 * isGameOver function in dominion.c for
 * CS362, Winter 2019, Assignment 3
 * ---------------------------------------*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

//note this function is currently found
//in dominion.c lines 390 - 415

int main(int argc, char** argv) {

printf("~~~Now testing isGameOver~~~\n");

//start up a game
struct gameState G;
int kCards[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };
int i = initializeGame(2, kCards, 3, &G);


//ONE WIN CONDITION --> GAME OVER
//Providence cards are zero, but <= 2 supply piles = 0
G.supplyCount[province] = 0;
int j = isGameOver(&G);
assert(j == 1);
printf("Passed: Providence cards are zero, thus game over.\n");


// supply piles are empty, but Providence cards exist
i = initializeGame(2, kCards, 3, &G);
G.supplyCount[province] = 1;
int k;
for(k = 0; k < 10; k++){
	G.supplyCount[kCards[k]] = 0;
}
j = isGameOver(&G);
assert(j == 1);
printf("Passed: Supply Piles are zero, thus game over.\n");



//BOTH WIN CONDITIONS AT THE SAME TIME --> GAME OVER
i = initializeGame(2, kCards, 3, &G);
G.supplyCount[province] = 0;
for(k = 0; k < 10; k++){
	G.supplyCount[kCards[k]] = 0;
}
j = isGameOver(&G);
assert(j == 1);

printf("Passed: Province count and Supply Piles are zero, thus game over.\n");

printf("~~~End testing isGameOver~~~\n");

return 0;
}

