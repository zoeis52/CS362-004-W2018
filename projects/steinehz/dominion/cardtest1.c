#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>

int main() {
	int i, j, k, ret, handPos, r, handCount;
	struct gameState *g = malloc(sizeof(struct gameState));

	//test smithy card functionality 1000 times for each player
	srand(time(NULL));
	for(k = 0; k < 1000; k++){
		for(i = 0; i < MAX_PLAYERS; i++){
			//make it so the current player has no cards to start
			g->deckCount[i] = 0;
			g->handCount[i] = 0;
			handPos = 0;
			g->whoseTurn = i;
			//can't draw more than max hand
			handPos = rand()%(MAX_HAND-3);
			//for the random number of cards, give a random card for each position
			for(j = 0; j < handPos; j++){
				r = rand()%(25);
				g->hand[i][j] = r;
				g->handCount[i]++;
			}
			//fill the deck with last random card
			for(j = 0; j < (MAX_DECK-handPos); j++){
				g->deck[i][j] = r;
				g->deckCount[i]++;
			}
			//make sure they have smithy so we can play it and test
			g->hand[i][handPos] = smithy;
			g->handCount[i]++;
			//after the effect, we should have 2 more cards in hand (since we discard smithy)
			handCount = g->handCount[i]+2;
			ret = cardEffect(smithy, 0, 0, 0, g, handPos, 0);
			//check to make sure card effect returned fine
			assert(ret == 0);
			//check to make sure the handCount was updated
			assert(handCount == g->handCount[i]);
			printf("Test passed! Returned fine and 3 new cards were added\n");
		}
	}

	return 0;
}
