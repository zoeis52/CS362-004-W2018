#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main () {
   int allowed_cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, remodel, tribute, smithy, council_room};
   int i = 0, drawn = 2, discarded = 1, handPos = 0, bonus = 0, ret;
   int choice1 = 0, choice2 = 0, choice3 = 0;

   struct gameState g, test;

   //test adventurer card functionality by making a copy of prev and making sure the correct things are the same
   initializeGame(2, allowed_cards, 100, &g);

   //To test if the handcount goes up by 2 for the player who plays it, we need a copy of original
   memcpy(&test, &g, sizeof(struct gameState));

   ret = cardEffect(adventurer, choice1, choice2, choice3, &test, handPos, &bonus);


   assert(ret == 0);
   //this assert will fail because of bug from assign 2
   //assert(test.handCount[0] == g.handCount[0] + drawn - discarded);
   //going to use if statements instead for this
   //First check if hand count for player is correct
   if (test.handCount[0] != g.handCount[0] + drawn - discarded) {
      printf("FAIL: Hand count after playing adventurer was not correct. Expected %d, got %d\n", g.handCount[0] + drawn - discarded, test.handCount[0]);
   }


   //Test if the two cards taken were treasure cards
   if (test.hand[0][test.handCount[0]-1] != copper && test.hand[0][test.handCount[0]-1] != silver && test.hand[0][test.handCount[0]-1] != gold) {
      printf("FAIL: First card taken was not a treasure card\n");
   }

   if (test.hand[0][test.handCount[0]-2] != copper && test.hand[0][test.handCount[0]-2] != silver && test.hand[0][test.handCount[0]-2] != gold) {
      printf("FAIL: Second card taken was not a treasure card\n");
   }


   //Test if the deckcount goes down by 2 for the 2 cards drawn
   if (test.deckCount[0] != g.deckCount[0] - drawn) {
      printf("FAIL: Deck count after playing adventurer was not correct. Expected %d, got %d\n", g.deckCount[0] - drawn, test.deckCount[0]);
   }

   //Test if the score changed - it should be the same as before
   if (scoreFor(0, &test) != scoreFor(0, &g)) {
      printf("FAIL: Score after playing adventurer was not correct. Expected %d, got %d\n", scoreFor(0, &g), scoreFor(0, &test));
   }


   //Test if the other player's state is the same - hand, deck, and score
   if (test.handCount[1] != g.handCount[1]) {
      printf("FAIL: Player 2's handcount changed after player 1 played adventurer. Expected %d, got %d\n", g.handCount[1], test.handCount[1]);
   }


   if (test.deckCount[1] != g.deckCount[1]) {
      printf("FAIL: Player 2's deckcount changed after player 1 played adventurer. Expected %d, got %d\n", g.deckCount[1], test.deckCount[1]);
   }


   if (scoreFor(1, &test) != scoreFor(1, &g)) {
      printf("FAIL: Score for player 2 changed when player 1 played adventurer. Expected %d, got %d\n", scoreFor(1, &g), scoreFor(1, &test));
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
   for (i = 0; i < 10; i++) {

      if (test.supplyCount[allowed_cards[i]] != g.supplyCount[allowed_cards[i]]) {
	 printf("FAIL: Kingdom card pile #%d did not contain the same number of cards\n", i);
      }

   }

   return 0;

}
