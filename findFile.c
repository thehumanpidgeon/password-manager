#include "passwordManager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * findFile(){
    //get the home location of the current user
    char *homeLocation = getEnv("home");

    //Allocate enough space for the string to contain the full path
    char *storageLocation = malloc(strlen(homeLocation)+37);

    //create the file path
    strcpy(storageLocation,homeLocation);
    strcat(storageLocation,"/.config/passwordManager/password.txt");

    //check that the file exists in the default location
    FILE *f = fopen(storageLocation,"r");
    
    //checks to see if file can be found
    while (f == NULL){
        //file cannot be found so llop until the user enter the loaction of the file that they wish to use
        printf("File cannot be located in the default position please enter the location of the file with the passwords.\n")
        fscanf(stdin,"%s",storageLocation);
        f = fopen(storageLocation,"r");
    }

    //close the file
    fclose(f);

    // return the string that contains the location of the file
    return storageLocation;
}