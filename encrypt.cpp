#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

void encrypt() {
	ifstream fin;
	fin.open("caesar_offset_4.pt");
	ofstream fout;
	fout.open("encrypt.txt");
	if (!fin) {
		cout << "Could not open input file.";
	}
	char ch;
	int temp = 0;
	int last = 0;
	while(!fin.eof()) {
		fin >> noskipws >> ch;
		temp = int(ch) + 4 + last;
		if (temp > 255) {
			last = temp - 255;
			fout << char(last);
		}
		else {
			last = temp;
			fout << char(last);
		}
	}
	fin.close();
	fout.close();
}

int main() {
	encrypt();
	return 0;
}