#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
 
void brute_force(int shift) {
  	ifstream fin;
	fin.open("caesar_brute_force.ct");
	ofstream fout;
	fout.open("brute_force.txt", ios::app);
	if (!fin) {
		cout << "Could not open input file.";
	}
	else {
		unsigned char ch;
		int temp, last = 0;
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
	for (int i=0; i < 10; i++) {
		brute_force(i);
	}
	return 0;
}