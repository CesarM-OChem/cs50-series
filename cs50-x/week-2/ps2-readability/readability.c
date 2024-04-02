#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int checkpunct(char c);
void printResult(int grade);

int main(void){
    int letters = 0, words = 0, sentences = 0;
    string text = get_string("Text: ");

    for(int i = 0, length = strlen(text); i < length; i++){
        if(isalpha(text[i])){
            letters++;
        }else if(isblank(text[i])){
            words++;
        }else if(checkpunct(text[i])){
            sentences++;
            if(i == length - 1){
                words++;
            }
        }
    }

    float index = 0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8;

    printResult((int)round(index));
}

int checkpunct(char c){
    switch(c){
        case '.':
            return 1;
        break;
        case '!':
            return 1;
        break;
        case '?':
            return 1;
        break;
        default:
            return 0;
        break;
    }
}

void printResult(int grade){
    if(grade < 1){
        printf("Before Grade 1\n");
    }else if(grade >= 16){
        printf("Grade 16+\n");
    }else{
        printf("Grade %i\n", grade);
    }
}