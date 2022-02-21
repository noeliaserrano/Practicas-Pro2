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
    tItemL users;
    tPosL data;
};

typedef tPosL tList;

void createEmptyList (tList*);
bool isEmptyList (tList);
tPosL first (tList);
tPosL last (tList);
tPosL next (tPosL, tList);
tPosL previous (tPosL, tList);
bool insertItem ();


#endif
