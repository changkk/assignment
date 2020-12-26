#include "cashBin.h"

// This part will be replaced by the cash Bin machine API

int cashBin::cashCounter() {
	int cash;
	cout << endl << "<<<<< Plese insert your cash >>>>>" << endl;
	cout << "Cash amount: ";
	while (!(cin >> cash)) {
		cout << "Wrong value. Please type number" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl << "Cash amount: ";
	}

	entireCash += cash;
	return cash;
}

bool cashBin::extractCash(int cash) {
	
	if (cash > entireCash) {
		cout<< "Not enough cash in the cash bin. Please call the maintenance team."<<endl;
		return false;
	}
	else {
		entireCash -= cash;
		return true;
	}
}