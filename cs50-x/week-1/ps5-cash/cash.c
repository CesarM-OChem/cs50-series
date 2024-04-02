#include <cs50.h>
#include <stdio.h>

#define MIN 0

int main(void){
    int change;

    do{
        change = get_int("Change owed: ");
    }while(change < MIN);

    int coins = 0;

    coins += change / 25;
    change %= 25;

    coins += change / 10;
    change %= 10;

    coins += change / 5;
    change %= 5;

    coins += change;

    printf("%i\n", coins);
}