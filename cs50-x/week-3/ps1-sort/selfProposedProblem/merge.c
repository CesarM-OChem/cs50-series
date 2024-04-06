#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

void sort(int list[], int size);
void createHalf(int array[], int half[], int start, int final);

int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./merge file_name.txt\n");
        return 1;
    }

    char row[MAX_LINE_LENGTH];
    FILE *inputFile = fopen(argv[1], "r");

    if(inputFile == NULL){
        printf("Cound't open the file.. Check if it exists!\n");
        return 2;
    }

    // Determines the number of lines of the file, hense the quantity of numbers
    int rowCounter = 0;

    while(fgets(row, MAX_LINE_LENGTH, inputFile) != NULL){
        rowCounter++;
    }

    rewind(inputFile);

    int list[rowCounter];

    // Fill the array with the numbers of the file
    for(int i = 0; i < rowCounter; i++){
        if(fgets(row, MAX_LINE_LENGTH, inputFile) != NULL){
            list[i] = atoi(row);
        }
    }

    sort(list, rowCounter);
    FILE *outputFile = fopen("answer.txt", "w");

    for(int i = 0; i < rowCounter; i++){
        fprintf(outputFile, "%d\n", list[i]);
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

void sort(int list[], int size){
    // Base case
    if (size == 1){
        return;
    }

    // Determines the size of the two halves of the original array that will be created
    int leftSize, rightSize;
    if(size % 2 == 0){
        leftSize = rightSize = size / 2;
    }else{
        leftSize = size / 2 + 1;
        rightSize = size / 2;
    }

    int leftHalf[leftSize], rightHalf[rightSize];

    createHalf(list, leftHalf, 0, leftSize);
    createHalf(list, rightHalf, leftSize, rightSize);

    sort(leftHalf, leftSize);
    sort(rightHalf, rightSize);

    // Indexes of the two halves and a flag to indicate that one of the halves was completely traversed
    // which happens when the index is igual to the half length
    int leftPos = 0, rightPos = 0;
    bool leftLast = false, rightLast = false;

    for(int i = 0; i < size; i++){
        if(leftPos == leftSize){leftLast = true;}
        if(rightPos == rightSize){rightLast = true;}
        
        // Checks left flag, than right flag and, if not in the end of any halves, compare the current
        // two numbers to find the smaller
        if(leftLast){
            list[i] = rightHalf[rightPos];
            rightPos++;
        }else if(rightLast){
            list[i] = leftHalf[leftPos];
            leftPos++;
        }else{
            if(leftHalf[leftPos] < rightHalf[rightPos]){
                list[i] = leftHalf[leftPos];
                leftPos++;
            }else{
                list[i] = rightHalf[rightPos];
                rightPos++;
            }
        }
        
    }
    return;
}

void createHalf(int array[], int half[], int start, int final){
    for(int i = 0; i < final; i++){
        half[i] = array[start + i];
    }

    return;
}