#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int k);

int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for(int i = 0, length = strlen(argv[1]); i < length; i++){
        if(!isdigit(argv[1][i])){
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]);

    string plaintext = get_string("Plaintext:  ");
    printf("Ciphertext: ");

    for(int i = 0, length = strlen(plaintext); i < length; i++){
        printf("%c", rotate(plaintext[i], k));
    }

    printf("\n");

    
    return 0;
}

char rotate(char c, int k){
    if(!isalpha(c)){
        return c;
    }

    if(isupper(c)){
        c = (c - 'A' + k) % 26 + 'A';
    }else{
        c = (c - 'a' + k) % 26 + 'a';
    }
    return c;
}