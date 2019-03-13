/*--------------------------------
* Author) Merry Caroline Purser
* February 5th, 2019
* The fourth unit test to test
* getCost function in dominion.c for
* CS362, Winter 2019, Assignment 3
* ---------------------------------------*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main(int argc, char **argv) {
        printf("~~~Testing getCost~~~\n");

        //Test all cards
	    if(getCost(curse) == 0){
	    	printf("Passed: curse\n");
	    } else {
	    	printf("ERROR: curse\n");
	    }


	    if(getCost(estate) == 2){
	    	printf("Passed: estate\n");
	    } else {
	    	printf("ERROR: estate\n");
	    }


	    if(getCost(duchy) == 5){
	    	printf("Passed: duchy\n");
	    } else {
	    	printf("ERROR: duchy\n");
	    }


	    if(getCost(province) == 8){
	    	printf("Passed: province\n");
	    } else {
	    	printf("ERROR: province\n");
	    }


	    if(getCost(copper) == 0){
	    	printf("Passed: copper\n");
	    } else {
	    	printf("ERROR: copper\n");
	    }


	    if(getCost(silver) == 3){
	    	printf("Passed: silver\n");
	    } else {
	    	printf("ERROR: silver\n");
	    }


	    if(getCost(gold) == 6){
	    	printf("Passed: gold\n");
	    } else {
	    	printf("ERROR: gold\n");
	    }


	    if(getCost(adventurer) == 6){
	    	printf("Passed: adventurer\n");
	    } else {
	    	printf("ERROR: adventurer\n");
	    }


	    if(getCost(council_room) == 5){
	    	printf("Passed: council_room\n");
	    } else {
	    	printf("ERROR: council_room\n");
	    }


	    if(getCost(feast) == 4){
	    	printf("Passed: feast\n");
	    } else {
	    	printf("ERROR: feast\n");
	    }


	    if(getCost(gardens) == 4){
	    	printf("Passed: gardens\n");
	    } else {
	    	printf("ERROR: gardens\n");
	    }


	    if(getCost(mine) == 5){
	    	printf("Passed: mine\n");
	    } else {
	    	printf("ERROR: mine\n");
	    }


	    if(getCost(remodel) == 4){
	    	printf("Passed: remodel\n");
	    } else {
	    	printf("ERROR: remodel\n");
	    }


	    if(getCost(smithy) == 4){
	    	printf("Passed: smithy\n");
	    } else {
	    	printf("ERROR: smithy\n");
	    }


	    if(getCost(village) == 3){
	    	printf("Passed: village\n");
	    } else {
	    	printf("ERROR: village\n");
	    }


	    if(getCost(baron) == 4){
	    	printf("Passed: baron\n");
	    } else {
	    	printf("ERROR: baron\n");
	    }


	    if(getCost(great_hall) == 3){
	    	printf("Passed: great_hall\n");
	    } else {
	    	printf("ERROR: great_hall\n");
	    }


	    if(getCost(minion) == 5){
	    	printf("Passed: minion\n");
	    } else {
	    	printf("ERROR: minion\n");
	    }


	    if(getCost(steward) == 3){
	    	printf("Passed: steward\n");
	    } else {
	    	printf("ERROR: steward\n");
	    }


	    if(getCost(tribute) == 5){
	    	printf("Passed: tribute\n");
	    } else {
	    	printf("ERROR: tribute\n");
	    }


	    if(getCost(ambassador) == 3){
	    	printf("Passed: ambassador\n");
	    } else {
	    	printf("ERROR: ambassador\n");
	    }


	    if(getCost(cutpurse) == 4){
	    	printf("Passed: cutpurse\n");
	    } else {
	    	printf("ERROR: cutpurse\n");
	    }


	    if(getCost(embargo)  == 2){
	    	printf("Passed: embargo\n");
	    } else {
	    	printf("ERROR: embargo\n");
	    }


	    if(getCost(outpost) == 5){
	    	printf("Passed: outpost\n");
	    } else {
	    	printf("ERROR: outpost\n");
	    }


	    if(getCost(salvager) == 4){
	    	printf("Passed: salvager\n");
	    } else {
	    	printf("ERROR: salvager\n");
	    }


	    if(getCost(sea_hag) == 4){
	    	printf("Passed: sea_hag\n");
	    } else {
	    	printf("ERROR: sea_hag\n");
	    }


	    if(getCost(treasure_map) == 4){
	    	printf("Passed: treasure_map\n");
	    } else {
	    	printf("ERROR: treasure_map\n");
	    }


        printf("~~~End Testing getCost~~~\n");
        return 0;

}
