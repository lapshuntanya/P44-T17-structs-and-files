#include "Card.h"
#define CREATE_OR_LOAD 0 //1-create, 0-load

int main()
{
    srand(time(0));
    FILE* file = nullptr;

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
}

