#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>

int main() {
     int i, k, j, r, ret, handPos, handCount, numActions = 1;
     struct gameState *g = malloc(sizeof(struct gameState));

     //test great hall functionality
     srand(time(NULL));
	g->numPlayers = MAX_PLAYERS;
	//500 times for each player
	for(k = 0; k < 500; k++){
          //for each player
          for (i = 0; i < MAX_PLAYERS; i++) {
               //set hand and deck to 0 for current player
			g->deckCount[i] = 0;
			g->handCount[i] = 0;
			handPos = 0;
			//can't draw more than max hand
			handPos = rand()%(MAX_HAND-4);
			//give them random cards to hand
			for(j = 0; j < handPos; j++){
				r = rand()%(25);
				g->hand[i][j] = r;
				g->handCount[i]++;
			}
			//also give last random card to the deck
			for(j = 0; j < (MAX_DECK-handPos); j++){
				g->deck[i][j] = r;
				g->deckCount[i]++;
			}
			//make sure great_hall is in deck to play it
			g->hand[i][handPos] = great_hall;
			g->handCount[i]++;
               //hand count should be the same after cause you get a new one and discard old one
               handCount = g->handCount[i];

               //make sure that numActions is correct after
               g->numActions = 0;

               ret = cardEffect(great_hall, 0, 0, 0, g, handPos, 0);
               assert(ret == 0);
               assert(handCount == g->handCount[i]);
               assert(numActions == g->numActions);
          }
     }
     printf("All tests passed! Returned fine and a new card was added and old was removed. Number of actions also right.\n");


     return 0;
}
