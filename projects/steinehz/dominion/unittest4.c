#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>

int main () {
     int i, randomCard, r;
     struct gameState *g = malloc(sizeof(struct gameState));

     srand(time(NULL));
     //tests numHandCards, for each player
     for (i = 0; i < MAX_PLAYERS; i++) {
          g->whoseTurn = i;

          g->handCount[i] = -1;
          r = numHandCards(g);
          assert(r == g->handCount[i]);
          printf("Test passed! Expected number of cards: %d. Actual number of cards: %d\n", r, g->handCount[i]);

          g->handCount[i] = 4;
          r = numHandCards(g);
          assert(r == g->handCount[i]);
          printf("Test passed! Expected number of cards: %d. Actual number of cards: %d\n", r, g->handCount[i]);

          randomCard = rand() % 100;
          g->handCount[i] = randomCard;
          r = numHandCards(g);
          assert(r == g->handCount[i]);
          printf("Test passed! Expected number of cards: %d. Actual number of cards: %d\n", r, g->handCount[i]);

     }


     return 0;
}
