#include <cs50.h>
#include <stdio.h>

int main(void){
    long number = 0;

    do{
        number = get_long("Number: ");
    }while(number == 0);

    //check number of digits
    long copy = number;
    int digits = 0;

    do{
        copy /= 10;
        digits++;
    }while(copy != 0);
    
    if(digits != 13 && digits != 15 && digits != 16){
        printf("INVALID\n");
        return 0;
    }

    
}