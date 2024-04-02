#include <cs50.h>
#include <stdio.h>

#define MIN 1
#define MAX 8

int main(void){
    int height = 0;
    do{
        height = get_int("Height: ");
    }while(height < MIN || height > MAX);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < height - 1 - i; j++){
            printf(" ");
        }

        for(int k = 0; k < i + 1; k++){
            printf("#");
        }

        printf("\n");
    }
}