#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include "bank.h"
#include "cardReader.h" // Card reader API

const bool cardInserted=true;

using namespace std;

void cardReader(bank& b1) {

	string cardNum = readCard();

	if (!b1.cardCheck(cardNum)) cardReader(b1);

	if (b1.pinCheck()) b1.selectAccount();
	else b1.goodbye();
	
}

int main() {

	// Turn on the ATM
	cashBin testCashBin;
	bank testBank(testCashBin);
	testBank.loadUserData();


	// This may be in the while loop (true) for the real-time system
	// while(true){
	if (cardInserted) {

		cardReader(testBank);

	}
	// }

	// Turn of the ATM
	testBank.saveUserData();

	return 0;
}