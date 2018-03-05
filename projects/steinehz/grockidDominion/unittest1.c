#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main () {
     int i, ret;

     //tests the getCost functions, from negative invalid range through the valid range and above
     for (i = -5; i < 30; i++) {
          ret = getCost(i);

          //start an if statement to check which card
          if (i == curse) {
               assert(ret == 0);
          }
          else if (i == estate) {
               assert(ret == 2);
          }
          else if (i == duchy) {
               assert(ret == 5);
          }
          else if (i == province) {
               assert(ret == 8);
          }
          else if (i == copper) {
               assert(ret == 0);
          }
          else if (i == silver) {
               assert(ret == 3);
          }
          else if (i == gold) {
               assert(ret == 6);
          }
          else if (i == adventurer) {
               assert(ret == 6);
          }
          else if (i == council_room) {
               assert(ret == 5);
          }
          else if (i == feast) {
               assert(ret == 4);
          }
          else if (i == gardens) {
               assert(ret == 4);
          }
          else if (i == mine) {
               assert(ret == 5);
          }
          else if (i == remodel) {
               assert(ret == 4);
          }
          else if (i == smithy) {
               assert(ret == 4);
          }
          else if (i == village) {
               assert(ret == 3);
          }
          else if (i == baron) {
               assert(ret == 4);
          }
          else if (i == great_hall) {
               assert(ret == 3);
          }
          else if (i == minion) {
               assert(ret == 5);
          }
          else if (i == steward) {
               assert(ret == 3);
          }
          else if (i == tribute) {
               assert(ret == 5);
          }
          else if (i == ambassador) {
               assert(ret == 3);
          }
          else if (i == cutpurse) {
               assert(ret == 4);
          }
          else if (i == embargo) {
               assert(ret == 2);
          }
          else if (i == outpost) {
               assert(ret == 5);
          }
          else if (i == salvager) {
               assert(ret == 4);
          }
          else if (i == sea_hag) {
               assert(ret == 4);
          }
          else if (i == treasure_map) {
               assert(ret == 4);
          }
          else if (i > 26 || i < 0){
		     assert(ret == -1);
	     }
          else {
               printf("Test Failed \n");
          }

     }
     printf("All tests passed!\n");

     return 0;
}
