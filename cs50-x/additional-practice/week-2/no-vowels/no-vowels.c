// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string input);

int main(int argc, string argv[])
{
    if (argc != 2){
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    
    printf("%s\n", replace(argv[1]));
    return 0;
}

string replace(string input){
    // Sinse at this week wasn't spoken about passing variables by reference and by value or even pointers
    // I decided to change the original string insted of creating a new string by copying character by character
    for (int i = 0, l = strlen(input); i < l; i++){
        switch (input[i])
        {
        case 'a':
            input[i] = '6';
            break;

        case 'e':
            input[i] = '3';
            break;
        case 'i':
            input[i] = '1';
            break;
        case 'o':
            input[i] = '0';
            break;
        
        default:
            break;
        }
    }

    return input;
}