#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <time.h>
int main(){
	int i, j, k, ret, handPos, r, handCount, numBuys;
	int otherPlayersHand[4];
	struct gameState *g = malloc(sizeof(struct gameState));

	//test council room functionality multiple times for each player
	srand(time(NULL));
	g->numPlayers = MAX_PLAYERS;
	//500 times for each player
	for(k = 0; k < 500; k++){
		//for each player
		for(i = 0; i < MAX_PLAYERS; i++){
			//set hand and deck to 0 for current player
			g->deckCount[i] = 0;
			g->handCount[i] = 0;
			handPos = 0;
			//randomly give buys
			g->numBuys = rand()%5;
			numBuys = g->numBuys+1;
			g->whoseTurn = i;
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
			//make sure council room is in deck to play it
			g->hand[i][handPos] = council_room;
			g->handCount[i]++;
			//handCount after the card is palyed should be greater
			handCount = g->handCount[i]+3;
			//give other players some hand and deck cards
			for(j = 0; j < MAX_PLAYERS; j++){
				if(j != i){
					g->discardCount[j] = 0;
					g->handCount[j] = rand()%MAX_HAND;
					g->deckCount[j] = 10;
					otherPlayersHand[j] = g->handCount[j]+1;
				}
			}
			ret = cardEffect(council_room, 0, 0, 0, g, handPos, 0);
			//returns the normal response
			assert(ret == 0);
			//need to check if game state conditions are met

			//this and some following asserts will fail, so use if statements instead
			//assert(handCount == g->handCount[i]);
			//fails because of bug introduced in last assign

			//check to make sure player got right amount of cards
			if (handCount != g->handCount[i]) {
			   printf("FAIL: Hand count after playing council_room was not correct. Expected %d, got %d\n", handCount, g->handCount[i]);
			}
			else {
			   printf("PASS: Correct hand count after playing council_room (+4)\n");
			}
			//check to make sure council increased the buys
			assert(numBuys == g->numBuys);

			//check if other players also got a card added
			for(j = 0; j < MAX_PLAYERS; j++){
				if(j != i) {
					if (g->handCount[j] != otherPlayersHand[j]) {
					   printf("FAIL: Hand count after playing council_room was not correct. Expected %d, got %d\n", g->handCount[i], otherPlayersHand[j]);
					}
					else {
					   printf("PASS: Correct hand count after playing council_room (+1 for everyone else)\n");
					}
				}
			}
		}
	}
	return 0;
}
