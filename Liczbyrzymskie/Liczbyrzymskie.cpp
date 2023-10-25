#include <iostream>
#include <string>
using namespace std;
int romToInt(string s) {
	bool correct = true;
	string romanNumber;
	cin >> romanNumber;
	int arabicNumber = 0;
	int romancheckval[7]{ 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < romanNumber.size(); i++) {
		if (romanNumber[i] == 'I') {
			if (romanNumber[i + 1] == 'V' || romanNumber[i + 1] == 'X') {
				if ((i > 0) && (romanNumber[i - 1] == 'I' || romanNumber[i - 1] == 'V')) {
					correct = false;
					break;
				}
				else {
					arabicNumber--;
					//romancheckval[0]++;
				}
			}
			else if (romanNumber[i + 1] == 'I' || i == romanNumber.size() - 1) {
				arabicNumber++;
				//romancheckval[0]++;
				continue;
			}
			else {
				correct = false;
				break;
			}
		}
		else if (romanNumber[i] == 'V') {
			if (romanNumber[i + 1] != 'I' && i < romanNumber.size() - 1) {
				correct = false;
				break;
			}
			else {
				arabicNumber += 5;
				//romancheckval[1]++;
			}
		}
		else if (romanNumber[i] == 'X') {
			if (romanNumber[i + 1] == 'I' || romanNumber[i + 1] == 'V' || romanNumber[i + 1] == 'X' || i == romanNumber.size() - 1) {
				arabicNumber += 10;
			//	romancheckval[2]++;
				continue;
			}
			else if (romanNumber[i + 1] == 'L' || romanNumber[i + 1] == 'C') {
				if (i > 0 && (romanNumber[i - 1] == 'X' || romanNumber[i - 1] == 'I' || romanNumber[i - 1] == 'L')) {
					correct = false;
					break;
				}
				else {
					arabicNumber -= 10;
					//romancheckval[2]++;
					continue;
				}
			}
			else {
				correct = false;
				break;
			}
		}
		else if (romanNumber[i] == 'L') {
			if (romanNumber[i + 1] == 'I' || romanNumber[i + 1] == 'V' || romanNumber[i + 1] == 'X' || i == romanNumber.size() - 1) {
				arabicNumber += 50;
				//romancheckval[3]++;
			}
			else {
				correct = false;
				break;
			}
		}
		else if (romanNumber[i] == 'C') {
			if (romanNumber[i + 1] == 'I' || romanNumber[i + 1] == 'V' || romanNumber[i + 1] == 'X' || romanNumber[i + 1] == 'L' || romanNumber[i + 1] == 'C' || i == romanNumber.size() - 1) {
				arabicNumber += 100;
				//romancheckval[4]++;
				continue;
			}
			else if (romanNumber[i + 1] == 'D' || romanNumber[i + 1] == 'M') {
				if ((i > 0 && romanNumber[i - 1] == 'M') || i == 0) {
					arabicNumber -= 100;
				//	romancheckval[4]++;
					continue;
				}
			}
			else {
				correct = false;
				break;
			}
		}
		else if (romanNumber[i] == 'D') {
			if (romanNumber[i + 1] == 'L' || romanNumber[i + 1] == 'I' || romanNumber[i + 1] == 'V' || romanNumber[i + 1] == 'X' || romanNumber[i + 1] == 'C' || i == romanNumber.size() - 1) {
				arabicNumber += 500;
				//romancheckval[5]++;
				continue;
			}
			else {
				correct = false;
				break;
			}
		}
		else if (romanNumber[i] == 'M') {
			arabicNumber += 1000;
			//romancheckval[6]++;
			continue;
		}
		else {
			correct = false;
		}

	}
	if (romanNumber.size() > 3) {
		for (int i = 0; i < romanNumber.size() - 3; i++) {
			if (romanNumber[i] == romanNumber[i + 3] == romanNumber[i + 2] == romanNumber[i + 1]) {
				correct = false;
			}
			else {
				continue;
			}
		}
	}
	/*for (int i = 0; i < 6; i++) {
		if (romancheckval[i] > 3) {
			correct = false;
		}
	}
	if (romancheckval[6] > 4) {
		correct == false;
	}*/
	if (correct) {
		return arabicNumber;
	}
	else {
		return 0;
	}
}
int main() {

}
