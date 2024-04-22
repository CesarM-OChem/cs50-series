// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 18278; // Stores A throw Z than AA throw ZZ than AAA and beyond (17576 + 676 + 26)
int size_count = -1;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_value = hash(word);
    if(table[hash_value] == NULL){
        return false;
    }else{
        int length = strlen(word);
        char copy[length + 1];
        copy[length] = '\0';

        for(int i = 0; word[i] != '\0'; i++){
            copy[i] = tolower(word[i]);
        }

        if(strcmp(table[hash_value]->word, copy) == 0){
            return true;
        }

        node *ptr = table[hash_value]->next;
        while(ptr != NULL){
            if(strcmp(ptr->word, copy) == 0){
                return true;
            }

            ptr = ptr->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Deals with one letter, two letter and three+ words allocating them in this order in the array
    // Considers that no word has apostrofe in the first three positions
    int sum = 0, length = strlen(word);

    if(length == 1){
        // A throw Z cases
        sum = toupper(word[0]) - 'A';
    }else if(length == 2){
        // Skips A throw Z (26 cases)
        sum = 26;
        // AA throw ZZ
        sum += toupper(word[0] - 'A') * 26 +
               toupper(word[1] - 'A');
    }else{
        // Skips A throw Z (26 cases) and AA throw ZZ (26 * 26 cases)
        sum = 26 + 26 * 26;
        // AAA and beyond
        sum += (toupper(word[0]) - 'A') * (26 * 26) +
              (toupper(word[1]) - 'A') * 26 +
              (toupper(word[2]) - 'A');
    }

    return sum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dictio = fopen(dictionary, "r");
    if(dictio == NULL){
        return false;
    }

    // Initialize Hash table
    for (int i = 0; i < N; i++){
        table[i] = NULL;
    }

    char c;
    char word[LENGTH + 1];
    int index = 0;

    while(fread(&c, sizeof(c), 1, dictio)){
        // Saves new word character by character
        if(c != '\n'){
            word[index] = c;
            index++;
        }else{
            //Hashes the whole word to the Hash Table
            word[index] = '\0';
            size_count = size();
            int hash_value = hash(word);

            node *n = malloc(sizeof(node));
            strcpy(n->word, word);

            if(table[hash_value] == NULL){
                table[hash_value] = n;
                n->next = NULL;
            }else{
                n->next = table[hash_value];
                table[hash_value] = n;
            }

            // Prepare for new word
            index = 0;
        }
    }

    fclose(dictio);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    size_count++;
    return size_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++){
        while(table[i] != NULL){
            node *ptr = table[i]->next;
            free(table[i]);
            table[i] = ptr;
        }
    }
    
    return true;
}
