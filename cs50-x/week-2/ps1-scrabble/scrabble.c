#include <cs50.h>
#include <stdio.h>

int main(void){
    char pointTable = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
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

    return 0;
}