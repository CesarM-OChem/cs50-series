#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

bool checkKey(string key);
char substitute(char c, string key);

int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if(!checkKey(argv[1])){
        printf("Key must contain 26 unique letters\n");
        return 1;
    }

    string plaintext = get_string("Plaintext:  ");

    printf("ciphertext: ");

    for(int i = 0, length = strlen(plaintext); i < length; i++){
        printf("%c", substitute(plaintext[i], argv[1]));
    }

    printf("\n");
    return 0;
}

bool checkKey(string key){
    if(strlen(key) != 26){
        return false;
    }

    for(int i = 0, length = strlen(key); i < length; i++){
        key[i] = toupper(key[i]);
    }

    for(int i = 0, length = strlen(key); i < length; i++){
        if(!isalpha(key[i])){
            return false;
        }

        if(index(key, key[i]) != rindex(key, key[i])){
            return false;
        }
    }

    return true;
}

char substitute(char c, string key){
    if(isupper(c)){
        return toupper(key[c - 'A']);
    }else if(islower(c)){
        return tolower(key[c - 'a']);
    }else{
        return c;
    }
}