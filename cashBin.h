#include <iostream>

using namespace std;

// This part will be replaced by the cash counter machine API / cashBin API
#define initialCash 1000000

class cashBin {
	int entireCash = initialCash;
public:
	cashBin() {};
	int cashCounter();
	bool extractCash(int cash);
};
