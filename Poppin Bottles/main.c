//
//  main.c
//  Poppin Bottles
//
//  Created by Josh Endter on 6/9/15.
//  Copyright (c) 2015 Josh Endter. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#import <stdlib.h>
#include <string.h>

// Declare functions
int fullPopFromMoney (int cash);
int fullPopFromEmptyPopBottles (int emptyPop);
int fullPopFromBottleCaps (int bottleCaps);
int leftoverEmptyPopBottles (int emptyPop);
int leftoverBottleCaps (int bottleCaps);


int main(int argc, const char * argv[]) {

    bool takingOrders = true;
    //int totalNumOfBottlesOrdered = 0;
    int numOfInitialFullPopBottles = 0;
    
    while ( takingOrders == true ) {
        numOfInitialFullPopBottles = 0;
        
        printf("How much money do you want to spend (type 'exit' to finish)? ");
        char buffer[20];
        scanf("%s", buffer);
        int cash = atoi(buffer);
        
        if ( strcmp(buffer, "exit")==0 ) {
            takingOrders = false;
        }else {
            int numOfInitialFullPopBottles = fullPopFromMoney(cash);
            int numOfFullPopFromEmptyPopBottles = fullPopFromEmptyPopBottles(numOfInitialFullPopBottles);
            int numOfFullPopFromBottleCaps = fullPopFromBottleCaps(numOfInitialFullPopBottles);
            int numOfTotalBottlesRecieved = numOfInitialFullPopBottles + numOfFullPopFromEmptyPopBottles + numOfFullPopFromBottleCaps;
            
            int numOfLeftoverEmptyPopBottles = leftoverEmptyPopBottles(numOfInitialFullPopBottles);
            int numOfLeftoverBottleCaps = leftoverBottleCaps(numOfInitialFullPopBottles);
            
            
            printf("\nYou recieve %d pop bottles. \n", numOfTotalBottlesRecieved);
            
            printf("  %d of those bottles will be from bottle recycling. \n", numOfFullPopFromEmptyPopBottles);
            printf("  %d of those bottles will be from bottle cap recycling. \n", numOfFullPopFromBottleCaps);
            
            printf("  You will have %d empty bottles left over. \n", numOfLeftoverEmptyPopBottles);
            printf("  You will have %d bottle caps left over. \n", numOfLeftoverBottleCaps);
            
        }
    }
    
    return 0;
}

int fullPopFromMoney (int cash) {
    return cash / 2;
}

// Recycling
int fullPopFromEmptyPopBottles (int emptyPop) {
    return emptyPop / 2;
}

int fullPopFromBottleCaps (int bottleCaps) {
    return bottleCaps / 4;
}

// Leftover recycling
int leftoverEmptyPopBottles (int emptyPop) {
    return emptyPop % 2;
}

int leftoverBottleCaps (int bottleCaps) {
    return bottleCaps % 4;
}