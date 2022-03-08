/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Noelia Serrano Abraldes LOGIN 1: noelia.serrano
 * AUTHOR 2: Pedro Chan Piñeiro LOGIN 2: pedro.chan.pineiro
 * GROUP: 1.3
 * DATE: ** / ** / **
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
#include <stdbool.h>

#define LNULL -1
#define MAX 25

typedef int tPosL;

typedef struct tList{
    tItemL Product[MAX];
    tPosL lastPos;
}tList;

void createEmptyList(tList*);

bool isEmptyList(tList);

tPosL first(tList);

tPosL last(tList);

tPosL next(tPosL, tList);

tPosL previous(tPosL, tList);

bool insertItem(tItemL, tPosL, tList*);

void deleteAtPosition(tPosL, tList*);

tItemL getItem(tPosL, tList);

void updateItem(tItemL, tPosL, tList*);

tPosL findItem(tProductId, tList);


#endif
