/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Noelia Serrano Abraldes LOGIN 1: noelia.serrano
 * AUTHOR 2: Pedro Chan Piñeiro LOGIN 2: pedro.chan.pineiro
 * GROUP: 1.3
 * DATE: 11 / 03 / 22
 */

#include "static_list.h"
#include <string.h>

void createEmptyList(tList* L){
    L->lastPos = LNULL;
}

bool isEmptyList(tList L){
    return L.lastPos==LNULL;
}

tPosL first(tList L){
    return 0;
}

tPosL last(tList L){
    return L.lastPos;
}

tPosL next(tPosL p, tList L){
    if(p==L.lastPos)
        return LNULL;
    else
        return ++p;
}

tPosL previous(tPosL p, tList L){
    return p--;
}

bool insertItem(tItemL d, tPosL p, tList* L){
    tPosL a;

    if(L->lastPos == MAX-1)
        return false;
    else{
        L -> lastPos++;
        if(p == LNULL)
            L -> Product[L->lastPos] = d;
        else{
            for (a = L->lastPos; a >= p + 1; a--)
                L->Product[a] = L->Product[a-1];
            L -> Product[p] = d;
        }
        return true;
    }
}

void deleteAtPosition(tPosL p, tList* L){
    tPosL a;

    //Solo tenemos un elemento i>lastPos-1, entonces lastPos se pone a -1
    //Si eliminamos el ultimo a > lastPos-1, lastPos se pone a -1
    for (a = p; a <= (L->lastPos-1); a++)
        L->Product[a] = L->Product[a+1];
    L->lastPos--;
}

tItemL getItem(tPosL p, tList* L){
    return L->Product[p];
}

void updateItem(tItemL d, tPosL p, tList* L){
    L->Product[p] = d;
}

tPosL findItem(tProductId t, tList L){
    tPosL a;

    if(isEmptyList(L))
        return LNULL;
    else {
        for (a = 0; (a <= L.lastPos) && (strcmp(L.Product[a].productId, t)); a++);

        if(a <= L.lastPos)
            return a;
        else
            return LNULL;
    }
}
