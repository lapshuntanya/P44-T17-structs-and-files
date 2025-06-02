#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

struct Card
{
	char name[100] = "noname";
	unsigned long number = 0;
	double cash = 0;

	void fillCard() {
		cout << "Input client`s name: ";
		cin.getline(name, 100);
		number = rand()*10'000 + rand();
		cash = 500;
	}
	void printCard() {
		cout << "===================================\n";
		cout << "Client: " << name << endl;
		cout << "Card:   " << number << endl;
		cout << "Cash:   " << cash << " UAH.\n";
		cout << "===================================\n";
	}
	void printLine() {
		cout << "| " << setw(12) << number << "| "
			<< setw(15) << name << "|"
			<< setw(7) << cash << "|\n";
	}

};
