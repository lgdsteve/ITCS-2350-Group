#pragma once
// C++ Program to delete the given
// line number from a file

#include <iostream>         // std input/output stream objects  (cout, cin)
#include <iomanip>          // used to manipulate strings (setfill, setw, setpercision)
#include <cctype>           // To force uppercase letters (toupper)
#include <fstream>			// file manipulation
#include <sstream>
#include <string>

using namespace std;


void DeleteAccount(const char *file_name, string sFNAccounts, int iAccNum) {
	int AccIndexNum = 0;								// Account to be deleted
	char c;												// char c will be the character retrieved from the AccountsList file
	int iLineNum = 1;									// Current line number

	// Print warning message and get the account number (as an index number) to delete 
	cout << "WARNING! This will perminently delete the account!" << endl;
	cout << "Enter the Index Number from the accounts list or 0 to exit: ";
	cin >> AccIndexNum;
	cout << endl;

	//Validate the entry and run the function
	if (AccIndexNum < iAccNum && AccIndexNum > 0) {			// If the number is above 0 and less than the number of accounts..
		ifstream ifs(sFNAccounts);							// Open the accounts file as read only
		
		ofstream ofs;										// Create the temp file to save changes to
		ofs.open("temp.txt", ofstream::out);					// and write the contents to the temp file.

		while (ifs.get(c)) {								// Get the current character (c). We're looking for the line number to delete (AccIndexNum)
			if (c == '\n') {								// If it's the end of line (\n)..
				iLineNum++;									// Increment the iLineNum to move to the next line.
			}
			if (iLineNum != AccIndexNum) {					// If the current line does not match the user supplied line 
				ofs << c;									// Get the new character from the file.
			}
		}

		ofs.close();										// Close the temp file
		ifs.close();										// Close the AccountsList file

		remove(file_name);									// Delete old AccountsList file
		rename("temp.txt", file_name);						// Rename the temp file to AccountList
		remove("temp.txt");									// Delete the temp file

		// Print successful deletion of record to the user
		cout << "Account record number " << AccIndexNum << " has been successfully deleted." << endl << endl;
	}
	else if (AccIndexNum == 0) {							// If the user entered 0, then return to the main menu without changes
		cout << "Returning to main menu..." << endl<< endl;
	}
	else {													// Any other entry, break the function without changes.
		cout << "Entry must be a number and less than " << iAccNum << endl;
	}
}
