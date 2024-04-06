#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

void sort(int list[], int size);

int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./selection file_name.txt\n");
        return 1;
    }

    char row[MAX_LINE_LENGTH];
    FILE *inputFile = fopen(argv[1], "r");

    if(inputFile == NULL){
        printf("Cound't open the file.. Check if it exists!\n");
        return 2;
    }

    int rowCounter = 0;

    while(fgets(row, MAX_LINE_LENGTH, inputFile) != NULL){
        rowCounter++;
    }

    rewind(inputFile);

    int list[rowCounter];

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
    for(int i = 0; i < size; i++){
        int minor = list[i];
        int position = i;
        for(int j = i; j < size; j++){
            if(list[j] < minor){
                minor = list[j];
                position = j;
            }
        }

        int temp = list[i];
        list[i] = minor;
        list[position] = temp;
    }
    return;
}