#include "Card.h"

int main()
{
    srand(time(0));

    Card pupkin;
    pupkin.fillCard();

    cout << endl;
    pupkin.printTitle();
    pupkin.printLine();
}

