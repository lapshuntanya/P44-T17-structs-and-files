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
	void printTitle() {
		cout << "| " << setw(12) << "Card" << "| "
			<< setw(15) << "Client" << "|"
			<< setw(7) << "Cash" << "|\n";
	}
	void printLine() {
		cout << "| " << setw(12) << number << "| "
			<< setw(15) << name << "|"
			<< setw(7) << cash << "|\n";
	}

	void saveToTextFile(FILE* file) {
		fprintf(file, "\n%s\n%lu %lf", name, number, cash);
	}
	void loadFromTextFile(FILE* file) {
		fscanf_s(file, "\n");
		fgets(name, 100, file); // "Pupkin Semen\n";
		name[strlen(name) - 1] = '\0'; // "Pupkin Semen\0";
		fscanf_s(file, "%lu %lf", &number, &cash);
	}

};
