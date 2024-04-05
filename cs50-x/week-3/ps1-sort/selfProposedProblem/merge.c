#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

void sort(int list[]);

int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./merge file_name.txt\n");
        return 1;
    }

    char row[MAX_LINE_LENGTH];
    FILE *file = fopen(argv[1], "r");

    if(file == NULL){
        printf("Cound't open the file.. Check if it exists!\n");
        return 2;
    }

    int rowCounter = 0;

    while(fgets(row, MAX_LINE_LENGTH, file) != NULL){
        rowCounter++;
    }

    rewind(file);

    int list[rowCounter];

    for(int i = 0; i < rowCounter; i++){
        if(fgets(row, MAX_LINE_LENGTH, file) != NULL){
            list[i] = atoi(row);
        }
    }

    fclose(file);
    return 0;
}

void sort(int list[]){

    return;
}