#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include "cashBin.h" // CashBin API

using namespace std;

class bank {
	unordered_map< string, pair < string, vector<string> > > userData;
	int account = 0;
	cashBin cb;
	string cardNum;
public:
	bank(cashBin cb1):cb(cb1) {};
	~bank() {};
	void loadUserData();
	void saveUserData();
	bool cardCheck(string cn);
	bool pinCheck();
	void goodbye();
	void showBalance();
	void deposit();
	void withdraw();
	void selectAccount();
	void serviceCheck();

};
