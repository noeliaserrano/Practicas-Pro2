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


void new(char *userId, char *productId, char *productCategory, float *productPrice, tList *L){
    //definicion de datos
}

void delete(char *productId, tList *L){
    tPosL p = findItem(productId, *L);
    tItemL aux;

    if(p == LNULL)
        printf("+ Error: Delete not possible\n");
    else{
        aux = getItem(p, *L);
        deleteAtPosition(p, L);

        printf("* Delete: product %s seller %s ", productId, aux.seller);

        //selecccion de categoria
        if(aux.productCategory == painting)
            printf("category %s ", "painting");
        else printf("category %s ", "book");

        printf("price %0.2f bids %d\n", aux.productPrice, aux.bidCounter);
    }

}

void bid(char *productId, char *userId, float *productPrice, tList *L){
    tPosL p = findItem(productId, *L);
    tItemL aux;
    aux = getItem(p, *L);

    if(p == LNULL || strcmp(aux.seller, aux.bidder) || aux.productPrice<*productPrice) //precio pujado mayor al precio inicial
        printf("+ Error: Bid not possible\n");      //podemos crear otro usuario

    else{ //buscar el producto, actualizar el precio, modificar el contador de pujas

        updateItem(aux, p, *L);
        aux.bidCounter++;

        printf("* Bid: product %s seller %s ", productId, userId); //como diferenciar los dos usuarios

        if(aux.productCategory == painting)
            printf("category %s ", "painting");
        else printf("category %s ", "book");

        printf("price %0.2f bids %d\n", productPrice, aux.bidCounter);
    }
}

void stats(tList list){
    //ver cuantos contadores hacen falta, poner los printf
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






