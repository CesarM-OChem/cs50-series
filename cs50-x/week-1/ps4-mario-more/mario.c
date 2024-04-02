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
        for(int space = 0; space < height - 1 - i; space++){
            printf(" ");
        }

        for(int hashtag = 0; hashtag < i + 1; hashtag++){
            printf("#");
        }

        printf("  ");

        for(int hashtag = 0; hashtag < i + 1; hashtag++){
            printf("#");
        }
        
        printf("\n");
    }
}