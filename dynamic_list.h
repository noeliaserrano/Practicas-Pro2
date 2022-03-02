/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Noelia Serrano Abraldes LOGIN 1: noelia.serrano
 * AUTHOR 2: Pedro Chan Piñeiro      LOGIN 2: pedro.chan.pineiro
 * GROUP: 1.3
 * DATE: ** / ** / **
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdlib.h>
#include <stdbool.h>

#define LNULL NULL

typedef struct tNode* tPosL;

struct tNode {
    tItemL data;
    tPosL next;
};

typedef tPosL tList;

void createEmptyList (tList*);
    /*Crea una lista vacía.
    PostCD: La lista queda inicializada y no contiene elementos. */

bool isEmptyList (tList);
    /*Determina si la lista esta vacia*/

tPosL first (tList);
    /*Devuelve la posición del primer elemento de la lista.
    PreCD: La lista no está vacía.*/

tPosL last (tList);
    /*Devuelve la posición del último elemento de la lista.
    PreCD: La lista no está vacía.*/

tPosL next (tPosL, tList);
    /*Devuelve la posición en la lista del elemento siguiente al de la posición indicada (o
    LNULL si la posición no tiene siguiente).
    PreCD: La posición indicada es una posición válida en la lista.*/

tPosL previous (tPosL, tList);
    /*Devuelve la posición en la lista del elemento anterior al de la posición indicada (o
    LNULL si la posición no tiene anterior).
    PreCD: La posición indicada es una posición válida en la lista.*/

bool insertItem (tItemL, tPosL, tList*);
    /*Inserta un elemento en la lista antes de la posición indicada. Si la posición es LNULL,
    entonces se añade al final. Devuelve un valor true si el elemento fue
    insertado; false en caso contrario.
    PreCD: La posición indicada es una posición válida en la lista o bien nula (LNULL).
    PostCD: Las posiciones de los elementos de la lista posteriores a la del
    elemento insertado pueden haber variado.*/

void deleteAtPosition (tPosL, tList*);
    /*Elimina de la lista el elemento que ocupa la posición indicada.
    PreCD: La posición indicada es una posición válida en la lista.
    PostCD: Las posiciones de los elementos de la lista posteriores a la de la
    posición eliminada pueden haber variado.*/

tItemL getItem(tPosL, tList*);
    /*Devuelve el contenido del elemento de la lista que ocupa la posición indicada.
    PreCD: La posición indicada es una posición válida en la lista.*/

void updateItem (tItemL, tPosL, tList*);
    /*Modifica el contenido del elemento situado en la posición indicada.
    PreCD: La posición indicada es una posición válida en la lista.
    PostCD: El orden de los elementos de la lista no se ve modificado.*/

tPosL findItem (tProductId, tList);
    /*Devuelve la posición del primer elemento de la lista cuyo identificador de
    producto se corresponda con el indicado (o LNULL si no existe tal elemento).*/

#endif
