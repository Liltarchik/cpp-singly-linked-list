#ifndef LABA4_H
#define LABA4_H

#include <iostream>

typedef struct SProduct {
    char name[100];
    char owner[100];
    int year;
    float price;
    struct SProduct *next;
} Tovar;

Tovar* initElement(const char* name, const char* owner, int year, float price);
void addToStart(Tovar* &start, Tovar* pNew);
void addToEnd(Tovar* &start, Tovar* pNew);
Tovar* find(Tovar* start, const char* keyName);
void printList(Tovar* start);
void delList(Tovar* &start);
Tovar* element_our_list();
Tovar* list(int count);
void deleteElement(Tovar* &start, const char* keyName);


std::ostream& operator<<(std::ostream& os, const Tovar& item);
// якщо б не ця команда, в laba4.cpp вмводило б помилку про те що оператор товару перезавантажений
#endif