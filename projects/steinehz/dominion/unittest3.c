#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>

int main () {
     int i, j = 0, randomCoin = 0, coinCount = 0;
     struct gameState *g = malloc(sizeof(struct gameState));

     //test updateCoins function, for each player and type of coin and bonus
     srand(time(NULL));

     //Check that it works for each player
     for (i = 0; i < MAX_PLAYERS; i++) {

          coinCount = 0;

          //Fill the hand with coins
          for (j = 0; j < g->handCount[i]; j++) {
                   //make a random coin choice
                   randomCoin = rand() % 3;
     	         if (randomCoin == 0) {
     	                  g->hand[i][j] = copper;
     	                  coinCount += 1;
     	         }
     	         else if (randomCoin == 1) {
     	                  g->hand[i][j] = silver;
     	                  coinCount += 2;
     	         }
     	         else if (randomCoin == 2) {
     	                 g->hand[i][j] = gold;
     	                 coinCount += 3;
     	         }

           }

           //Test out updateCoins to see if it gets correct coin count
           updateCoins(i, g, 0);

           printf("Expected coin count: %d. Actual coin count: %d \n", coinCount, g->coins);
           assert(coinCount == g->coins);


           //Test again with an updated value (to see if the bonus works)
           coinCount += 1;
           updateCoins(i, g, 1);

           printf("Expected coin count: %d. Actual coin count: %d \n", coinCount, g->coins);
           assert(coinCount == g->coins);
        }

     return 0;
}
