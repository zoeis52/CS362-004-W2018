#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>

int main () {
     int allowed_cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, remodel, tribute, smithy, council_room};
     int i = 0, drawn = 2, discarded = 1, handPos = 0, bonus = 0, ret, num_players, turn, j;
     int choice1 = 0, choice2 = 0, choice3 = 0;

     struct gameState g, test;

     srand(time(NULL));

     for (i = 0; i < 1000; i++) {
          //generate random number of players
          num_players = rand()%(MAX_PLAYERS);

          //test adventurer card functionality by making a copy of prev and making sure the correct things are the same
          initializeGame(num_players, allowed_cards, 100, &g);
          if (num_players != 0) {
               turn = rand()%num_players;
               g.whoseTurn = turn;
          }

          //To test if the handcount goes up by 2 for the player who plays it, we need a copy of original
          memcpy(&test, &g, sizeof(struct gameState));

          ret = cardEffect(adventurer, choice1, choice2, choice3, &test, handPos, &bonus);
          if (ret != 0) {
               printf("FAIL: adventurer card effect did not return 0\n");
          }

          //First check if hand count for player is correct
          if (test.handCount[test.whoseTurn] != g.handCount[test.whoseTurn] + drawn - discarded) {
             printf("FAIL: Hand count after playing adventurer was not correct. Expected %d, got %d\n", g.handCount[test.whoseTurn] + drawn - discarded, test.handCount[test.whoseTurn]);
          }

          //Test if the two cards taken were treasure cards
          if (test.hand[test.whoseTurn][test.handCount[test.whoseTurn]-1] != copper && test.hand[test.whoseTurn][test.handCount[test.whoseTurn]-1] != silver && test.hand[test.whoseTurn][test.handCount[test.whoseTurn]-1] != gold) {
             printf("FAIL: First card taken was not a treasure card\n");
          }
          if (test.hand[test.whoseTurn][test.handCount[test.whoseTurn]-2] != copper && test.hand[test.whoseTurn][test.handCount[test.whoseTurn]-2] != silver && test.hand[test.whoseTurn][test.handCount[test.whoseTurn]-2] != gold) {
             printf("FAIL: Second card taken was not a treasure card\n");
          }

          //Test if the deckcount goes down by 2 for the 2 cards drawn
          if (test.deckCount[test.whoseTurn] != g.deckCount[test.whoseTurn] - drawn) {
             printf("FAIL: Deck count after playing adventurer was not correct. Expected %d, got %d\n", g.deckCount[test.whoseTurn] - drawn, test.deckCount[test.whoseTurn]);
          }

          //Test if the score changed - it should be the same as before
          if (scoreFor(test.whoseTurn, &test) != scoreFor(test.whoseTurn, &g)) {
              printf("FAIL: Score after playing adventurer was not correct. Expected %d, got %d\n", scoreFor(test.whoseTurn, &g), scoreFor(test.whoseTurn, &test));
          }

          //Test if the other player's state is the same - hand, deck, and score
          for (j = 0; j < num_players; j++) {
               if (j != test.whoseTurn) {
                    if (test.handCount[j] != g.handCount[j]) {
                       printf("FAIL: Player %d's handcount changed after player 1 played adventurer. Expected %d, got %d\n", j, g.handCount[1], test.handCount[1]);
                    }
                    if (scoreFor(j, &test) != scoreFor(j, &g)) {
                       printf("FAIL: Score for player %d changed when player 1 played adventurer. Expected %d, got %d\n", j, scoreFor(1, &g), scoreFor(1, &test));
                    }
               }
          }

          //Test if victory cards piles are the same
          if (test.supplyCount[estate] != g.supplyCount[estate]) {
             printf("FAIL: Number of estate cards differed. Expected %d, got %d\n", g.supplyCount[estate], test.supplyCount[estate]);
          }

          if (test.supplyCount[duchy] != g.supplyCount[duchy]) {
             printf("FAIL: Number of duchy cards differed. Expected %d, got %d\n", g.supplyCount[duchy], test.supplyCount[duchy]);
          }


          if (test.supplyCount[province] != g.supplyCount[province]) {
             printf("FAIL: Number of province cards differed. Expected %d, got %d\n", g.supplyCount[province], test.supplyCount[province]);
          }

          //Test if kingdom card piles are the same
          for (j = 0; j < 10; j++) {
             if (test.supplyCount[allowed_cards[j]] != g.supplyCount[allowed_cards[j]]) {
       	          printf("FAIL: Kingdom card pile #%d did not contain the same number of cards\n", j);
             }

          }

     }

     return 0;
}
