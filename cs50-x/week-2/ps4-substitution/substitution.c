#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool checkKey(string key);

int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if(strlen(argv[1]) != 26){
        printf("Key must contain 26 characters\n");
        return 1;
    }

    if(!checkKey(argv[1])){
        printf("Key must contain 26 unique letters\n");
        return 1;
    }

    
}

bool checkKey(string key){
    int sum = 0, reference = 0;
    char c = 'A';

    for(int i = 0, length = strlen(key); i < length; i++){
        if(!isalpha(key[i])){
            return false;
        }

        reference += c - 'A' + 1;
        c++;

        if(isupper(key[i])){
            sum += key[i] - 'A' + 1;
        }else{
            sum += key[i] - 'a' + 1;
        }
    }

    if(sum != reference){
        return false;
    }else{
        return true;
    }
}

