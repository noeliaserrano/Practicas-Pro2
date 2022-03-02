/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Noelia Serrano Abraldes LOGIN 1: noelia.serrano
 * AUTHOR 2: Pedro Chan Piñeiro LOGIN 2: pedro.chan.pineiro
 * GROUP: 1.3
 * DATE: 04 / 03 / 22
 */

#include "dynamic_list.h"
#include <string.h>

void createEmptyList (tList *L){
    *L = LNULL;
}

bool isEmptyList (tList L){
    return L == LNULL;
}

tPosL first (tList L){

}

tPosL last (tList L){ //no se comprueba que la lista este vacia, porque es una precondicion
    tPosL aux = NULL;

    if(L == LNULL)
        return LNULL;

    aux = L;
    while(aux -> next != LNULL)
        aux = next(aux, L);

    return aux;
}

tPosL next (tPosL p, tList L){

}

tPosL previous (tPosL p, tList L){
    tPosL aux = NULL;
    if(L == p)
        return LNULL;

    aux = first(L);
    while (aux ->next != p)
        aux = next(aux, L);

    return aux;
}

bool insertItem (tItemL, tPosL p, tList *L){

}

void deleteAtPosition (tPosL p, tList *L){
    tPosL q;

    if(p == *L)
        *L = (*L)->next;
    else if(p->next == LNULL){
        for (q = *L; q->next != p; q = q->next);
        q->next == LNULL;
    }
    else{
        q = p->next;
        p->data = q->data;
        p->next = q->next;
        p = q;
    }
    free(p);
}

tItemL getItem(tPosL p, tList *L){

}

void updateItem (tItemL d, tPosL p, tList *L){
    p->data = d;
}

tPosL findItem (tProductId t, tList L){

}
