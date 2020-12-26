#include "bank.h"


void bank::loadUserData() {
	cout << "Loading the user data..." << endl << endl;
	ifstream inFile("Data/userData.txt");

	while (inFile.good())
	{
		string key, pin, balance;
		getline(inFile, key);
		getline(inFile, pin);
		getline(inFile, balance);
		userData[key].first = pin;

		while (balance != "" && inFile.good()) {
			userData[key].second.push_back(balance);
			getline(inFile, balance);
		}

	}
	inFile.close();
}

void bank::saveUserData() {
	ofstream outFile("Data/tmp.txt");
	for (auto d : userData) {
		outFile << d.first << endl;
		outFile << d.second.first << endl;
		for (int i = 0; i < d.second.second.size(); i++) {
			outFile << d.second.second[i] << endl;
		}
		outFile << "" << endl;
	}
	outFile.close();
	remove("Data/userData.txt");
	rename("Data/tmp.txt", "Data/userData.txt");
	cout << "Data saved." << endl;
}

bool bank::cardCheck(string cn) {

	if (userData.find(cardNum) == userData.end()) {
		cout << endl << "<<< Wrong card information. Swipe the card again. >>>" << endl;
		return false;
	}
	cardNum = cn;
	return true;

}

bool bank::pinCheck() {
	string pin = userData[cardNum].first;
	int pinCnt = 0;
	string pinTmp;
	cout << "Pin number (example: 1234): ";
	cin >> pinTmp;
	bool res;

	while (pinCnt < 2 && pinTmp != pin) {
		pinCnt++;
		cout << "Wrong pin number. Try again " << pinCnt << "/3" << endl;
		cout << "Pin number: ";
		cin >> pinTmp;
	}

	if (pinTmp == pin) return true;
	else {
		cout << "You typed wrong pin numbers 3 times. Try again later" << endl;
		return false;
	}
}

void bank::selectAccount() {
	vector<string>& balance = userData[cardNum].second;
	cout << endl << "<<<<<< Please select the account number. >>>>>" << endl;
	cout << "Current account list: ";

	for (int i = 0; i < balance.size(); i++) {
		cout << i + 1 << " ";
	}
	cout << endl << "Acount number: ";
	int tmp;
	while (!(cin >> tmp)) {
		cout << "Wrong value. Please type number." << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl << "Account number: ";
	}
	account = tmp - 1;
	serviceCheck();
}

void bank::serviceCheck() {
	cout << "-----------------------------------------------------------------" << endl;
	cout << "---------------------------- WELCOME ----------------------------" << endl;
	cout << "----- Please press button for the service, and press enter: -----" << endl;
	cout << "--  1.Balance, 2.Deposit, 3.Withdraw, 4.Change Account, 5.Quit --" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------" << endl;

	int service;
	cout << "Service number: ";
	while (!(cin >> service)) {
		cout << "Wrong value. Please type number." << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl << "Service number: ";
	}

	switch (service) {
	case 1: showBalance(); break;
	case 2: deposit(); break;
	case 3: withdraw(); break;
	case 4: selectAccount(); break;
	case 5: goodbye(); break;
	default:
		cout << "Wrong number. Try again" << endl << endl;
		serviceCheck();
		break;
	}

}

void bank::showBalance() {
	vector<string>& balance = userData[cardNum].second;
	cout << endl << "<<<<< Your current balance is: " << balance[account] << " >>>>>"<< endl << endl;
	serviceCheck();
}

void bank::deposit() {
	vector<string>& balance = userData[cardNum].second;
	int cash = cb.cashCounter();
	int curBalance = stoi(balance[account]);
	balance[account] = to_string(curBalance + cash);
	showBalance();
}

void bank::withdraw() {
	vector<string>& balance = userData[cardNum].second;
	int cash;
	cout << endl << "Plese type the amount of cash to withdraw: ";
	while (!(cin >> cash)) {
		cout << "Wrong value. Please type number" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl << "Plese type the amount of cash to withdraw: ";
	}
	int curBalance = stoi(balance[account]);
	if (cash > curBalance) {
		cout << "The ammount exceeds the current balance." << endl <<endl;
		serviceCheck();
	}
	else if (cb.extractCash(cash)){
		balance[account] = to_string(curBalance - cash);
		showBalance();
	}
	else serviceCheck();
}

void bank::goodbye() {
	cout << endl << "<<<<< Thank you for using our service. See you next time. >>>>>" << endl << endl;
}
