#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

void decrypt() {
	ifstream fin;
	fin.open("caesar_offset_7.ct");
	ofstream fout;
	fout.open("decrypt.txt");
	if (!fin) {
		cout << "Could not open input file.";
	}
	else {
		unsigned char ch;
		int temp, last = 0;
		int shift = 7;
		while(!fin.eof()) {
			fin >> noskipws >> ch;
			temp = int(ch) - last - shift;
			if (temp < 0) {
				fout << char(temp + 255);
			}
			else {
				fout << char(temp);
			}
			last = int(ch);
		}
	}	
	fin.close();
	fout.close();
}

int main() {
	decrypt();
	return 0;
}