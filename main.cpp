#include "laba4.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    Tovar* start = nullptr;
    char c;
    srand(time(0));

    do {
        system("cls");
        cout << "i. Init list (reset to empty)\n";
        cout << "s. Add to start\n";
        cout << "a. Add to end\n";
        cout << "p. Print list\n";
        cout << "d. Delete list\n";
        cout << "f. Find element\n";
        cout << "e. Exit\n";
        cout << "m. del element\n";
        cout << "Choose: ";
        cin >> c;

        // Очищення буфера вводу
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (c) {
            case 'i':
                delList(start);
                start = nullptr;
                cout << "List initialized (empty).\n";
                break;

            case 's':
                addToStart(start, element_our_list());
                cout << "Element added to start.\n";
                break;

            case 'a':
                addToEnd(start, element_our_list());
                cout << "Element added to end.\n";
                break;

            case 'p':
                if (start == nullptr) {
                    cout << "List is empty.\n";
                } else {
                    printList(start);
                }
                break;

            case 'd':
                delList(start);
                start = nullptr;
                cout << "List deleted.\n";
                break;

            case 'f': {
                if (start == nullptr) {
                    cout << "List is empty.\n";
                    break;
                }
                char keyName[100];
                cout << "Enter name to find: ";
                cin.getline(keyName, 100);
                Tovar* found = find(start, keyName);
                if (found) {
                    cout << "Found:\n" << *found << endl;
                } else {
                    cout << "Not found.\n";
                }
                break;
            }
        case 'm' : {
                    if (start == nullptr) {
                        cout << "List is empty.\n";
                        break;
                    }
                    char keyName[100];
                    cout << "Enter name to delete: ";
                    cin.getline(keyName, 100);
                    deleteElement(start, keyName);
                    break;
        }

            case 'e':
                delList(start);  // Очищаємо пам'ять перед виходом
                return 0;

            default:
                cout << "Invalid command. Try again.\n";
        }
        system("pause");
    } while (true);

    return 0;
}