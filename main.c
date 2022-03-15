/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Noelia Serrano Abraldes LOGIN 1: noelia.serrano
 * AUTHOR 2: Pedro Chan Piñeiro LOGIN 2: pedro.chan.pineiro
 * GROUP: 1.3
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif


void new(tList *L){

}
void delete(tList *L){

}
void bid(){

}
void stats(tList list){

}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4) {

    switch (command) {
        case 'N':
            printf("********************\n");
            printf("Command: %s %c %s %s %s %s\n", commandNumber, command, param1, param2, param3, param4);
            break;
        case 'S':
            printf("********************\n");
            printf("Command: %s %c %s %s %s %s\n", commandNumber, command, param1, param2, param3, param4);
            break;
        case 'B':
            printf("********************\n");
            printf("Command: %s %c %s %s %s %s\n", commandNumber, command, param1, param2, param3, param4);
            break;
        case 'D':
            printf("********************\n");
            printf("Command: %s %c %s %s %s %s\n", commandNumber, command, param1, param2, param3, param4);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}






