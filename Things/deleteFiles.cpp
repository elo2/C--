/*
    This is a simple program I wrote
    to delete all of the files that are created
    upon execution of Assignment2 Dictionary program
    so that I can be lazy and don't have to delete them myself :-)
*/

#include <iostream>
#include <sstream> //needed to get from char to string
#include <string>
using namespace std;

void deleteFile() {
    //All files are named A.txt through Z.txt
    for (int i = 65; i < 91; i++) { //ascii for letters A to Z
        stringstream ss; //had to use sstream to get a char into a string
        string letter;
        ss << char(i); //sstream gets the character
        ss >> letter; //letter then gets the string from sstream
        string fileName(letter + ".txt"); //concatenates the string to make a filename
        remove(fileName.c_str()); //from the std:: library
    }
}

int main() {
    deleteFile();
    return 0;
}