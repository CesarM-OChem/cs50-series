#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512
 
typedef uint8_t BYTE;

int checkSignature(BYTE block[]);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: ./recover name_file.raw\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");

    if(card == NULL){
        printf("Unable to open file\n");
        return 1;
    }
    
    BYTE block[BLOCK_SIZE];
    int firstFileCreated = 0; // Usefull to only try to close a file if the first one is already opened
    char name[sizeof("images/000.jpeg") + 1] = "images/000.jpeg"; //directory needs to exist before running application
    int file_number = 0;
    FILE *file = NULL;

    while(fread(&block, BLOCK_SIZE, 1, card) != 0){
        if(checkSignature(block)){
            if(firstFileCreated){
                fclose(file);
            }

            file = fopen(name, "w");

            if(file == NULL){
                printf("Unable to create new file. Lack of memory or you could try to create 'images' directory first\n");
                return 1;
            }
            
            file_number++;
            snprintf(name, sizeof(name), "images/%03d.jpeg", file_number);
            firstFileCreated = 1;
        }

        if(firstFileCreated){
            fwrite(&block, BLOCK_SIZE, 1, file);
        }
    }

    fclose(file);
    fclose(card);
    return 0;
}

int checkSignature(BYTE block[]){
    if(block[0] != 0xff || block[1] != 0xd8 || block[2] != 0xff){
        return 0;
    }

    if(block[3] < 0xe0 || block[3] > 0xef){
        return 0;
    }

    return 1;
}