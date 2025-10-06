/*
 * Author: James L.
 *
 * program to take user string input and append it to the end of a file
 * then take file contents, reverse them, and write them to new file
 */

#include <iostream>
#include <fstream>

using namespace std;

//function prototypes
void appendData(ofstream &file, string fileName, string input);
void reverseDocument(ifstream &readFile, ofstream &writeFile, string readFileName, string writeFileName);

int main(){

	//string to hold user input
	string userString;

	//get user string
	cout << "Enter a string!: ";
	getline(cin, userString);

	//open file output stream and append user string to end of file
	ofstream appendFile;
	appendData(appendFile, "CSC450_CT5_mod5.txt", userString);
	appendFile.close();

	//open input and output streams to read from file and write to new file
	ifstream readFile;
	ofstream reverseFile;
	reverseDocument(readFile, reverseFile, "CSC450_CT5_mod5.txt", "CSC450-mod5-reverse.txt");
	readFile.close();
	reverseFile.close();

	return 0;
}

//function to append data to end of a file
void appendData(ofstream &file, string fileName, string input){

	//open file and append
	file.open(fileName, ios::app);

	//if file opens, append to it, otherwise do not append
	if(file.is_open()){
		file << input << endl;
		cout << "String was appended to file." << endl;
	}
	else{
		cout << "File could not be opened!" << endl;
	}

	//close when done
	file.close();
}

//function to reverse characters in file and write reversed chars to new file
void reverseDocument(ifstream &readFile, ofstream &writeFile, string readFileName, string writeFileName){

	//string for current line in file
	string currLine;

	//open file to read from
	readFile.open(readFileName, ios::in);

	//open file to write to, truncating if file already exists
	writeFile.open(writeFileName, ios::out | ios::trunc);

	//check if read file is open
	if (readFile.is_open()) {
		//check if write file is open
		if (writeFile.is_open()) {
			//run while read file has lines to read from
			while(getline(readFile, currLine)){

				//reverse characters in current line and write to file
				for(int i = currLine.length() - 1; i >= 0; --i){
					writeFile << currLine[i];
				}

				//end line after each line read
				writeFile << endl;
			}
		}
		//indicate write file was not opened
		else{
			cout << "File to write to cannot be opened!" << endl;
		}
	}
	//indicate read file was not opened
	else{
		cout << "File to read from cannot be opened!" << endl;
	}

	//close when done
	readFile.close();
	writeFile.close();
}
