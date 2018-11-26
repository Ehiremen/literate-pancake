/*
 * Author: Ehiremen Ekore
 * Started: 11/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NOMORECARDS -42

char* revealCard(int cardNumber);
int getRandomCard();
int dealUnusedRandomCard(int* usedCards, int* noOfUsedCardsPtr);
int checkCardPlayed(int* topCardPtr, int cardPlayed, int* player, int sizeOfPlayerHand);

int main() {
    int cards[52];
    /*
     * You'd assume that setting the max size of player hands to 36 is okay, but there's no guarantee that they'd
     * not pick a 37th card.
     */
    int playerOne[46];
    int countPlayerOneHand=0, leftInPlayerOneHand=0;
    int playerTwo[46];
    int countPlayerTwoHand=0, leftInPlayerTwoHand=0;
    int usedCards[52];

    int *noOfUsedCardsPtr = NULL;
    int noOfUsedCards = 0;
    noOfUsedCardsPtr = &noOfUsedCards;
    int currentChoice, playerTurn = 1;
    int starterCard, topCard;
    int* topCardPtr = NULL;
    topCardPtr = &topCard;

    //initialize the cards array to store the different cards
    //basically, cards run from 1 to 52
    //this is important to avoid conflicts when members of player hands are still 0
    for(int i=0; i<52; i++){
        cards[i] = i+1;
    }

    //create a starter card and add it to the array of used cards.
    starterCard = dealUnusedRandomCard(usedCards, &noOfUsedCards);
    printf("The starting card is: %s\n\n", revealCard(starterCard));
    topCard = starterCard;
    usedCards[1] = starterCard;
    noOfUsedCards++;

    //Initialize each player's hand with 5 cards
    printf ("Player 1 goes first. Player 1's hand is: \n");
    for(int i=0; i<5; i++){
        playerOne[i] = dealUnusedRandomCard(usedCards, &noOfUsedCards);
        printf("%i %s\n", i, revealCard(playerOne[i]));
        countPlayerOneHand++;
        leftInPlayerOneHand++;
    }

    printf("Player 2's hand is: \n");
    for(int k=0; k<5; k++){
        playerTwo[k] = dealUnusedRandomCard(usedCards, &noOfUsedCards);
        printf("%i %s\n", k, revealCard(playerTwo[k]));
        countPlayerTwoHand++;
        leftInPlayerTwoHand++;
    }

    while(1){
        //basically checks if even or odd. Using this to switch between players 1 and 2
        if(playerTurn&1){
            printf("Player 1, your turn. Please pick a card from your hand by typing the index\n");
            printf("Use 52 to show your hand, and -1 to skip\n");
        } else{
            printf("Player 2, your turn. Please pick a card from your hand by typing the index\n");
            printf("Use 52 to show your hand, and -1 to skip\n");
        }

        printf("The card to play on is: %s\n", revealCard(topCard));
        scanf(" %d", &currentChoice);
        if((currentChoice>52)||(currentChoice<-1)){
            printf("Invalid choice, please retry\n");
        }
        //deal the player a new card
        else if(currentChoice == -1){
            printf("Player skipped");
            if(playerTurn&1){
                playerOne[countPlayerOneHand]= dealUnusedRandomCard(usedCards, &noOfUsedCards);

                if(playerOne[countPlayerOneHand]==NOMORECARDS){
                    return 0;
                }else {
                    printf("Your new card is %s\n", revealCard(playerOne[countPlayerOneHand]));
                    countPlayerOneHand++;
                    leftInPlayerOneHand++;
                }
            } else{
                playerTwo[countPlayerTwoHand]= dealUnusedRandomCard(usedCards, &noOfUsedCards);

                if(playerTwo[countPlayerTwoHand]==NOMORECARDS){
                    return 0;
                }else {
                    printf("Your new card is %s\n", revealCard(playerTwo[countPlayerTwoHand]));
                    countPlayerTwoHand++;
                    leftInPlayerTwoHand++;
                }
            }
        }
        //re-iterate through their available cards and let the player pick an action again
        else if(currentChoice == 52){
            if(playerTurn&1){
                for(int index=0; index<countPlayerOneHand; index++){
                    if(playerOne[index]>-1){
                        printf("%i %s\n", index, revealCard(playerOne[index]));
                    }
                }
            } else{
                for(int index=0; index<countPlayerTwoHand; index++){
                    if(playerTwo[index]>-1){
                        printf("%i %s\n", index, revealCard(playerTwo[index]));
                    }
                }
            }
            continue;
        }
        else{
            if(playerTurn&1){
                if(checkCardPlayed(&topCard, currentChoice, playerOne, countPlayerOneHand) == 0) continue;
                else{
                    leftInPlayerOneHand--;
                }
            } else{
                if(checkCardPlayed(&topCard, currentChoice, playerTwo, countPlayerTwoHand) == 0) continue;
                else {
                    leftInPlayerTwoHand--;
                }
            }
        }
        playerTurn++;

        if(leftInPlayerOneHand==0){
            printf("Player 1 wins\n");
            break;
        }
        if (leftInPlayerTwoHand==0){
            printf("Player 2 wins\n");
            break;
        }
    }
    return 0;
}

int getRandomCard(){
    int randomChoice = 0;

    //not using rand() and srand(TIME) because they return the same value until the program is re-compiled
    //using time(NULL) is the simplest readily guaranteed way to get somewhat varying values
    randomChoice += time(NULL)%52;
    randomChoice = ((randomChoice%52) + 1);

    return randomChoice;
}

char* revealCard(int cardNumber){
    char* cardInText = calloc(25, sizeof(char));

    int valueOfCard, suitOfCard;
    valueOfCard = cardNumber%13;
    //remove 1 from cardNumber before dividing so that int division gives a unique value for every 13 values
    suitOfCard = (cardNumber - 1)/13;

    switch (valueOfCard){
        case 1:
            strcpy(cardInText, "Ace of ");
            break;

        case 2:
            strcpy(cardInText, "2 of ");
            break;

        case 3:
            strcpy(cardInText, "3 of ");
            break;

        case 4:
            strcpy(cardInText, "4 of ");
            break;

        case 5:
            strcpy(cardInText, "5 of ");
            break;

        case 6:
            strcpy(cardInText, "6 of ");
            break;

        case 7:
            strcpy(cardInText, "7 of ");
            break;

        case 8:
            strcpy(cardInText, "8 of ");
            break;

        case 9:
            strcpy(cardInText, "9 of ");
            break;

        case 10:
            strcpy(cardInText, "10 of ");
            break;

        case 11:
            strcpy(cardInText, "Jack of ");
            break;

        case 12:
            strcpy(cardInText, "Queen of ");
            break;

        case 0:
            strcpy(cardInText, "King of ");
            break;
    }

    switch (suitOfCard){
        case 0:
            strcat(cardInText, "Hearts");
            break;

        case 1:
            strcat(cardInText, "Diamonds");
            break;

        case 2:
            strcat(cardInText, "Clubs");
            break;

        case 3:
            strcat(cardInText, "Spades");
            break;
    }

    return  cardInText;
}

int dealUnusedRandomCard(int* usedCards, int* noOfUsedCardsPtr){
    int tempCard;
    int index = *noOfUsedCardsPtr;
    while(1){
        int tempCheckValue = 0;
        tempCard = getRandomCard();
        //check if the tempCard has already been drawn
        if( (*noOfUsedCardsPtr)==52){
            printf("\nUnable to draw a new card. Game inconclusive\n");
            return NOMORECARDS;
        } else{
            for(int j=0; j<index; j++){
                if (tempCard == usedCards[j]){
                    tempCheckValue = 1;
                }
            }

            if (tempCheckValue == 0){
                usedCards[index] = tempCard;
                (*noOfUsedCardsPtr) += 1;
                break;
            }
        }
    }
    return tempCard;
}

int checkCardPlayed(int* topCardPtr, int cardPlayed, int* player, int sizeOfPlayerHand){
    int playerHasCard=0, cardMatchesTopCard=0, tempCardsMatch=0;
    int tempCard = player[cardPlayed];
    int tempTopCard = *topCardPtr;

    //A check for repetition. If the card has already been played, this catches it.
    if (tempCard == -1){
        printf("Sorry, you already played that card\n");
        return 0;
    }

    for(int i=0; i<sizeOfPlayerHand; i++){
        if (tempCard == player[i]){
            playerHasCard = 1;
            //set the played card to -1 to show it's out of the player's hand.
            player[i] = -1;
        }
    }

    //Confirm to the console that player has the card they are trying to play
    if (playerHasCard == 1){
        printf("Trying to play %s\n", revealCard(tempCard));

        //do the face values match?
        if(((tempCard)%13)==((tempTopCard)%13)){
            printf("Card successfully played\n");
            (*topCardPtr) = tempCard;
            cardMatchesTopCard = 1;
        }
        //do the suits match?
        else if(((tempCard-1)/13)==((tempTopCard-1)/13)) {
            printf("Card successfully played\n");
            (*topCardPtr) = tempCard;
            cardMatchesTopCard = 1;
        }
        else {
            printf("Neither card suits nor values work. Please try another card or skip\n");
        }
    }
    else{
        printf("Sorry, you don't have that card\n");
    }

    return cardMatchesTopCard;
}
