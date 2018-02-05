#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>

int main () {
     int ret = 0, i = 0, j = 0, randomCard = 0;
	struct gameState *state = malloc(sizeof(struct gameState));

	//tests isGameOver function, with all 3 possible conditions
	srand(time(NULL));

     //Test province condition
	state->supplyCount[province] = 0;
	ret = isGameOver(state);
	assert(ret == 1);
	printf("Test passed! The return value of isGameOver was %d when the province count was set to zero\n", ret);

     //Test full supply condition
     for(i = 0; i < 25; i++){
		state->supplyCount[i] = 10;
	}
	ret = isGameOver(state);
	assert(ret == 0);
	printf("Test passed! The return value of isGameOver was %d when all the supply counts were greater than 0\n", ret);

     //Test 3 stacks empty condition, randomly generate random stacks
	for(j = 0; j < 1000; j++){
          //make 3 random stacks empty
		for(i = 0; i < 3; i++){
			randomCard = rand()%25;
			if(state->supplyCount[randomCard] == 0){
				i--;
			}
			state->supplyCount[randomCard] = 0;
		}
          //test the random stacks
		ret = isGameOver(state);
		assert(ret == 1);
          printf("Test passed! The return value of isGameOver was %d when 3 random supply counts were 0\n", ret);

          //fill them all back up again for re run
		for(i = 0; i < 25; i++){
			state->supplyCount[i] = 10;
		}
	}

     return 0;
}
