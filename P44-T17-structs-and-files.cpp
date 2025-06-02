#include "Card.h"
#include "ArrayTemplate.h"
#define CREATE_OR_LOAD 1 //1-create, 0-load

int main()
{
    srand(time(0));
    FILE* file = nullptr;
/*
    Card pupkin;
#if CREATE_OR_LOAD == 1
    pupkin.fillCard(); //create card
#else
    fopen_s(&file, "bank.txt", "r");
    if (file != nullptr) {
        pupkin.loadFromTextFile(file);
        fclose(file);
    }
#endif

    cout << endl;
    pupkin.printTitle();
    pupkin.printLine();
    pupkin.cash += 50;

    fopen_s(&file, "bank.txt", "w");
    // file =  fopen("bank.txt", "w");
    if (file != nullptr) {
        pupkin.saveToTextFile(file);
        fclose(file);
    }
    */

    Card* arr = nullptr;    //масив клієнтів
    int NClients = 0;       //розмір масиву = кількість

#if CREATE_OR_LOAD == 0
    NClients = 3;
    arr = new Card[3]{
        {"Pupkin Semen", 123456789, 150.99},
        {"Shevchenko Taras", 1212121212, 999.99},
        {"Ukrainka Lesya", 543215432, 650.5}
    };
#else
    //load
    fopen_s(&file, "bank.txt", "r");
    if (file == nullptr) cout << "ERROR: not loaded!\n";
    else {
        fscanf_s(file, "%d", &NClients);
        arr = new Card[NClients];
        for (int i = 0; i < NClients; i++)
        {
            arr[i].loadFromTextFile(file);
        }
        fclose(file);
    }
#endif

//===============================================================
    int menu = 0;
    char temp[100] = "";
    Card temp_card;
    unsigned long temp_number = 0;
    double temp_cash = 0;
    int id = -1;
    do
    {
        cout << "+++++++++++++++++++++++++++\n";
        cout << "|\t MENU:\n";
        cout << "+++++++++++++++++++++++++++\n";
        cout << "| 0 - Exit and Save\n";
        cout << "| 1 - Show list of cliens\n";
        cout << "| 2 - Open a new card\n";
        cout << "| 3 - Topup card\n";
        cout << "+++++++++++++++++++++++++++\n";
        cout << ">>> ";
        cin >> menu;

        switch (menu)
        {
        default: cout << "Error: try again!\n";    break;
        case 0: cout << "Bye!\n"; break;
        case 1:
            if (NClients == 0) {
                cout << "List is empty!\n";
                break;
            }
            temp_card.printTitle();
            for (int i = 0; i < NClients; i++)
            {
                arr[i].printLine();
            }
            break;
        case 2:
            cin.ignore();
            temp_card.fillCard();
            addItemBack(arr, NClients, temp_card);
            break;
        case 3:
            cout << "Input number of card: ";
            cin >> temp_number;
            cout << "Input cash: ";
            cin >> temp_cash;
            id = -1;
            for (int i = 0; i < NClients; i++) {
                if (arr[i].number == temp_number) {
                    id = i;
                    break;
                }
            }
            if (id == -1) cout << "Not found\n";
            else {
                arr[id].cash += temp_cash;
                arr[id].printCard();
            }
            break;
        }

    } while (menu != 0);

//===============================================================

    fopen_s(&file, "bank.txt", "w");
    if (file == nullptr) cout << "NOT saved!!!\n";
    else {
        fprintf(file, "%d", NClients);
        for (int i = 0; i < NClients; i++)
        {
            arr[i].saveToTextFile(file);
        }
        fclose(file);
        cout << "Saved!\n";
    }
}

