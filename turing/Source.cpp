#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	
	ifstream myFile;
	int fileSelect = 0;
	while (fileSelect > 4 || fileSelect < 1) {
		cout << "Pasirinkite faila nuskaityti" << endl;
		cout << "1.txt\n2.txt\n3.txt\n4.txt" << endl;
		cin >> fileSelect;
		switch (fileSelect) {
		case 1: { myFile.open("1.txt"); break; }
		case 2: { myFile.open("2.txt"); break; }
		case 3: { myFile.open("3.txt"); break; }
		case 4: { myFile.open("4.txt"); break; }
		default: { cout << "Neteinkamas pasirinkimas, bandykite dar karta"; break; }
		}
	}

	int index, lineCount = 0;
	string tape, currentState[100], nextState[100];
	char currentSymbol[100], nextSymbol[100], moveTape[100];

	myFile >> index;
	myFile >> tape;

	while (!myFile.eof()) {
		myFile >> currentState[lineCount] >> currentSymbol[lineCount] >> nextSymbol[lineCount] >> moveTape[lineCount] >> nextState[lineCount];
		lineCount++;
	}

	myFile.close();
	lineCount--;

	int n = tape.length();
	string newState = "0";
	string head = " ";

	for (int j = 0; j < n - 1; j++) head.append(" ");

	while (newState != "X") {
		for (int i = 0; i < lineCount; i++) {
			if (newState == currentState[i]) {
				if (currentSymbol[i] == tape[index]) {
					tape[index] = nextSymbol[i];
					newState = nextState[i];
					if (newState == "X") { 
						break; 
					}
					if(moveTape[i] == 'R') {
						head[index] = ' ';
						index++;
						head[index] = '^';
					}
					if (moveTape[i] == 'L') {
						head[index] = ' ';
						index--;
						head[index] = '^';
					}
				}
			}
		}
		system("cls");
		cout << tape << endl;
		cout << head << endl;
	}

	return 0;
}