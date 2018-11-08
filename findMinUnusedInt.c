/*
 * Author: Ehiremen Ekore
 * Started: 11/2018
 */

#include <stdio.h>
#include <stdlib.h>

int getLeastUnusedPositiveInt(int* inputArray, int arraySize){
    int minInt;
    int possibleAnswersArray[(arraySize)];
    int tempCheck = 0;

    /*
     * The idea is that if the array has n numbers, I only need to check it against n numbers
     * If all n checks fail, then (n+1) is the answer I seek
     */
    for(int index=0; index<=arraySize; index++){
        possibleAnswersArray[index] = index + 1;
    }

    for(int i=0; i<=(arraySize); i++){

        for(int k=0; k<=arraySize; k++){
            if (possibleAnswersArray[i] == inputArray[k]) {
                tempCheck++;
            }
        }

        /*
         * If a check from possibleAnswersArray is not in the inputArray, that check is the answer
         */
        if (tempCheck==0){
            minInt = possibleAnswersArray[i];
            break;
        }
        tempCheck = 0;
        minInt = possibleAnswersArray[i]+1;
    }
    return minInt;
}

int main() {
    printf("Program by Ehiremen Ekore...\n");
    printf("\tThis program takes in an array of integers and returns the lowest positive\n"
           "integer not in the input array\n\n");

    int lengthOfArray = 2;
    //Dynamically allocate the input array because we do not have an arbitrary size
    int* intArray = calloc(lengthOfArray, sizeof(int));
    int nOfUsedArraySpots = 0;
    int leastUnusedPositiveInt;

    printf("Input your integers:\n");
    for (int i = 0; i < lengthOfArray; i++){
        scanf("%i", &intArray[i]);
        if (getchar()=='\n') break;

        //This block increases the allocated memory once the second-to-last memory slot is used
        //Avoid doubling the allocated memory each time to avoid wasting memory with larger input arrays
        if (i == (lengthOfArray - 1)) {
            lengthOfArray += 5;
            realloc(intArray, lengthOfArray * sizeof(int));
        }
        nOfUsedArraySpots++;
    }

    //Sanity check. Making sure the input entered is ALL that's being used
    printf("Array members: ");
    for(int i=0; i<=nOfUsedArraySpots; i++){
        printf("%i ", intArray[i]);
    }

    leastUnusedPositiveInt = getLeastUnusedPositiveInt(intArray, nOfUsedArraySpots);
    printf("\nLeast unused positive integer: %i", leastUnusedPositiveInt);

    return 0;
}