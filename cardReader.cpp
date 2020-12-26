#include "cardReader.h"

// This part will be replaced by the card reader machine API

string readCard() {
	int cardNum;

	cout << "Card Number (example: 1000~1010): ";
	while (!(cin >> cardNum)) {
		cout << "Wrong value. Please type number." << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl << "Card Number (example: 11450): ";
	}
	string tmp = "#";
	tmp += to_string(cardNum);

	return tmp;

}