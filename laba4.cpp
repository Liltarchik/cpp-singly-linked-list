#include "laba4.h"
#include <iostream>
#include <cstring>


using namespace std;

// Реалізація функцій
Tovar* initElement(const char* name, const char* owner, int year, float price) {
    Tovar* newElem = new Tovar;
    strcpy(newElem->name, name);
    strcpy(newElem->owner, owner);
    newElem->year = year;
    newElem->price = price;
    newElem->next = nullptr;
    return newElem;
}

void addToStart(Tovar* &start, Tovar* pNew) {
    if (pNew == nullptr) return;
    pNew->next = start;
    start = pNew;
}

void addToEnd(Tovar* &start, Tovar* pNew) {
    if (pNew == nullptr) return;
    pNew->next = nullptr;
    if (start == nullptr) {
        start = pNew;
        return;
    }
    Tovar* wp = start;
    while (wp->next != nullptr) wp = wp->next;
    wp->next = pNew;
}

Tovar* find(Tovar* start, const char* keyName) {
    Tovar* wp = start;
    while (wp != nullptr) {
        if (strcmp(wp->name, keyName) == 0) return wp;
        wp = wp->next;
    }
    return nullptr;
}

void printList(Tovar* start) {
    Tovar* wp = start;
    while (wp != nullptr) {
        cout << *wp << endl; // Використовуємо перевантажений оператор і от для чого команда в laba4.h
        wp = wp->next;
    }
}

void delList(Tovar* &start) {
    while (start != nullptr) {
        Tovar* delP = start;
        start = start->next;
        delete delP;
    }
}

Tovar* element_our_list()
{
    char name[100], owner[100];
    int year;
    float price;

    cout << "Print nazva: ";
    cin.getline(name, 100);



    cout << "Print owner: ";
    cin.getline(owner, 100);

    cout << "print year: ";
    cin >> year;
    cout << "Print cina: ";
    cin >> price;

    return initElement(name, owner, year, price);

}
Tovar* list(int count) {
    Tovar* start = nullptr;
    for (int i = 0; i < count; i++) {
        cout << "Tovar " << i + 1;
        Tovar* newItem = element_our_list();
        addToEnd(start, newItem);
    }
    return start;
}

ostream& operator<<(ostream& os, const Tovar& item) {
    os << "Nazva: " << item.name
       << ", Owner: " << item.owner
       << ", Year: " << item.year
       << ", Cina: " << item.price;
    return os;
}

void deleteElement(Tovar* &start, const char* keyName) {
    if (start == nullptr) {
        return;
    }

    if (strcmp(start->name, keyName) == 0) {
        Tovar* temp = start;
        start = start->next;
        delete temp;
        cout << "Deleted successfully.\n";
        return;
    }

    Tovar* prev = start;
    Tovar* curr = start->next;

    while (curr != nullptr) {
        if (strcmp(curr->name, keyName) == 0) {
            prev->next = curr->next;
            delete curr;
            cout << "Deleted successfully.\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Element not found.\n";
}