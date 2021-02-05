#include "passwordManager.h"
#include <stdlib.h>
#include <string.h>

char * encrypt(char *plainText,char *key){
    unsigned passwordLength = strlen(plainText);
    char *cryptText = malloc(passwordLength);
    unsigned char *keyHash = hashString(key);
    for (int i = 0;i < strlen(keyHash);++i)
        printf("The value is byte %d is %0X\n",i,*(keyHash + i));
    for (int i = 0;i < passwordLength;++i){
        unsigned char currentChar = *(plainText + i) ^ *(keyHash + i);
        printf("Current char %d is %u\n",i,currentChar);
        *(cryptText + i) = currentChar;
    }
    return cryptText;
}

unsigned char * hashString(unsigned char *key){
    unsigned stringLength = strlen(key);
    unsigned char random = 0;
    unsigned char *hash = malloc(stringLength * stringLength); 
    for (int i = 0;i < stringLength;++i){
        srand(*(key + (stringLength/2 + i)%stringLength));
        for(int g = 0;g < stringLength;++g){
            printf("Byte %d:\tValue:%0X\n",i*stringLength + g,*(hash + i*stringLength + g));
            *(hash + i*10 + g) = 0;
            random = rand();
            *(hash + i*stringLength + g) = *(key + g) ^ random;
            printf("\tValue:%0X Inputs: %0X and %0X\n",*(hash + i*stringLength + g),*(key + g),random);
        }
    }
    return hash;
}