#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score(string s);

int pointTable[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void){
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int p1 = score(player1);
    int p2 = score(player2);
    
    if(p1 > p2){
        printf("Player 1 wins!");
    }else if(p1 < p2){
        printf("Player 2 wins!");
    }else{
        printf("Tie!");
    }
}

int score(string s){
    int points = 0;

    for(int i = 0, length = strlen(s); i < length; i++){
        if(isalpha(s[i]) != 0){
            points += pointTable[toupper(s[i]) - 'A'];
        }
    }

    return points;
}